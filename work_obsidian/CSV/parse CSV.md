https://habr.com/ru/articles/765066/



void Core::parseCSV()

{
std::ifstream data("test.csv");
std::string line;
std::vector<std::vector<std::string> > parsedCsv;
while(std::getline(data,line))
{
	std::stringstream lineStream(line);
	std::string cell;
	std::vector<std::string> parsedRow;
	while(std::getline(lineStream,cell,','))
	{
	parsedRow.push_back(cell);
	}

	parsedCsv.push_back(parsedRow);
}
};
