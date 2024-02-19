static bool csv_init(CsvFsm_t* Node,
			char separator,
			int32_t fetch_index, char* const out_text, uint32_t size) {
			bool res = false;
	        LOG_DEBUG(CSV, "Init: Separator:%c", separator);
		    if(Node) {
			            Node->separator = separator;
			            Node->init_done = true;
			            Node->fetch_done = false;
			            Node->prev_char = 0x00;
			            Node->state = CSV_STATE_INIT;
			            Node->input = CSV_INPUT_UNDEF;
			            Node->cnt = 0;
			            Node->position = 0;
			            Node->i = 0;
			            Node->out_buff = out_text;
			            Node->out_size = size;
			            Node->fetch_index = fetch_index;
		  LOG_DEBUG(CSV, "ValMaxSize:%u byte FetchIndex: %d",size, fetch_index);
		            res = true;
			        }
		  return res;
}


uint32_t csv_cnt(const char* const text, char separator) {
	    bool res = false;
	    size_t len = strlen(text);
	    	LOG_DEBUG(CSV, "Text:[%s] Size:%u byte Separator:%c", text, len, separator);
	    	CsvFsm_t Node;
	    	csv_init(&Node, separator, -1, NULL, 0);
	    uint32_t i = 0;
	    	for(i = 0; i < len; i++) {
				            Node.input = CSV_INPUT_UNDEF;
				            res = csv_cnt_proc(&Node, text[i]);
				        }
	     	Node.input = CSV_INPUT_END;
	     	res = csv_cnt_proc(&Node, 0x00);

	return Node.cnt;
}
bool csv_parse_text(const char* const in_text, char separator, uint32_t index,
		        char* const out_text, uint32_t size) {
	    bool res = false;

	    if(in_text && out_text) {
        	size_t len = strlen(in_text);
		LOG_DEBUG(CSV, "InText:[%s] Size:%u Sep:%c Index:%u", in_text, len, separator, index);
	        CsvFsm_t Item={0};
	        csv_init(&Item, separator, index, out_text, size);
	        uint32_t i = 0;
	        for(i = 0; i < len; i++) {
		        Item.input = CSV_INPUT_UNDEF;
	                res = csv_cnt_proc(&Item, in_text[i]);
			}
		Item.input = CSV_INPUT_END;
		res = csv_cnt_proc(&Item, 0x00);

		res = false;
	        if(Item.fetch_done ) {
			            if(0==Item.error_cnt){
																	                    res = true;
			              }
	        }
	    }
    return res;
}

static CsvInput_t csv_symbol_2_input(CsvFsm_t* CsvFsm,
		                                     char symbol) {
	    if(symbol == CsvFsm->separator) {
		            CsvFsm->input = CSV_INPUT_SEP;
			        } else {
					        CsvFsm->input = CSV_INPUT_NOT_SEP;
						    }
	        return CsvFsm->input;
}

static bool csv_cnt_proc(CsvFsm_t* Node, char symbol) {
	    bool res = false;
	        if(Node) {
			  Node->symbol = symbol;
			  if(CSV_INPUT_UNDEF == Node->input) {
			  csv_symbol_2_input(Node, symbol);
			  }
	        CsvNodeDiag(Node);

		switch(Node->state) {
			case CSV_STATE_INIT: res = csv_cnt_init_proc(Node); break;
		        case CSV_STATE_ACCUMULATE: res = csv_cnt_acc_proc(Node); break;
		        case CSV_STATE_SEP: res = csv_cnt_sep_proc(Node); break;
		        case CSV_STATE_END: res = csv_cnt_end_proc(Node); break;
		        default: break;
			}
			
		Node->prev_char = symbol;
		
		}
		return res;
}


tatic bool csv_cnt_init_proc(CsvFsm_t* Node) {
	    bool res = false;
	        /*LOG_DEBUG(CSV, "ProcInit %c Input:%s", Node->symbol, CsvInput2Str(Node->input)); */
	        if(Node) {
			switch(Node->input) {
				case CSV_INPUT_NOT_SEP: {
							Node->cnt++;
						  	Node->i = 0;
							res=csv_add_letter(Node, 0,   Node->symbol, false);
					                Node->state = CSV_STATE_ACCUMULATE;
					        } break;
			        case CSV_INPUT_SEP: {
					                Node->i = 0;
						            res=csv_add_letter(Node, 0,   0, true);
					                Node->cnt++;
					            Node->position++;
						    Node->state = CSV_STATE_SEP;
					        } break;
			         case CSV_INPUT_END: {
	 					     Node->state = CSV_STATE_END;
						     Node->i = 0;
						     res=csv_add_letter(Node, 0,   0, true);
						     Node->cnt++;
						 } break;
			        default: break;
																	            }
				    }
		    return res;
}

// обработчик состояния акумулятора
//
static bool csv_cnt_acc_proc(CsvFsm_t* Node) {
	    bool res = false;
	        /* LOG_DEBUG(CSV, "ProcAcc %c Input:%s", Node->symbol, CsvInput2Str(Node->input)); */
	        if(Node) {
			switch(Node->input) {
				case CSV_INPUT_NOT_SEP: { /*SaveChar*/
							Node->state = CSV_STATE_ACCUMULATE;
							Node->i++;
							res = csv_add_letter(Node,   Node->i,Node->symbol, false);
							} break;
				case CSV_INPUT_SEP: {
							    Node->i++;
							    res = csv_add_letter(Node,   Node->i,0, true);
							    Node->i = 0;
							    Node->position++;
							    Node->state = CSV_STATE_SEP;
						    } break;
				case CSV_INPUT_END: {
							    Node->i++;
							    res = csv_add_letter(Node,   Node->i, 0x00, true);
							    Node->state = CSV_STATE_END;
						    } break;
				default:
						    res = false;
						    break;
			}
		}
		return res;
}

static bool csv_cnt_sep_proc(CsvFsm_t* Node) {
	    bool res = false;
	        /*LOG_DEBUG(CSV, "ProcSep %c Input:%s", Node->symbol, CsvInput2Str(Node->input));*/
	        if(Node) {
		        switch(Node->input) {
				        case CSV_INPUT_NOT_SEP: {
								  Node->cnt++;
								  res=csv_add_letter(Node, 0,Node->symbol, false);
								  Node->state = CSV_STATE_ACCUMULATE;
								} break;
					case CSV_INPUT_SEP: {
								    res=csv_add_letter(Node, 0,0, true);
								    Node->position++;
								    Node->state = CSV_STATE_SEP;
								    Node->cnt++;
							    } break;
					case CSV_INPUT_END: {
								    res=csv_add_letter(Node, 0,0, false);
								    Node->state = CSV_STATE_END;
								    Node->cnt++;
							    } break;
					default:
							    break;
			}
		}
		return res;
}

static bool csv_cnt_end_proc(CsvFsm_t* Node) {
	    bool res = false;
	        LOG_DEBUG(CSV, "ProcEnd %c Input:%s", Node->symbol, CsvInput2Str(Node->input));
		    if(Node) {
		    	    switch(Node->input) {
				    case CSV_INPUT_NOT_SEP: {
								    res = false;
								    Node->i = 0;
								    Node->out_buff[0] = 0x00;
								    Node->state = CSV_STATE_END;
							    } break;
				    case CSV_INPUT_SEP: {
								res = false;
								Node->i = 0;
								Node->out_buff[0] = 0x00;
								Node->state = CSV_STATE_END;
							} break;
				    case CSV_INPUT_END: {
								res = false;
								Node->i = 0;
								Node->out_buff[0] = 0x00;
								Node->state = CSV_STATE_END;
							} break;
				    default:
							break;
			    }
		    }
		    return res;
}


