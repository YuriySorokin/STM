поиск вызвавшего прерывания в handler
https://microsin.net/programming/arm-troubleshooting-faq/stm32-freertos-debugging-hard-fault-and-other-exceptions.html

Default_Handler:
   /* Загрузка адреса регистра управления прерываниями в r3. */
   ldr r3, NVIC_INT_CTRL_CONST
   /* Загрузка значения регистра управления прерываниями в r2 из

      адреса, находящегося в r3. */
   ldr r2, [r3, 0]
   /* Номер прерывания находится в младшем байте - очистка всех других бит. */
   uxtb r2, r2

Infinite_Loop:
   /* Теперь садимся в бесконечный цикл, номер выполненного прерывания

      находится в r2. */
   b  Infinite_Loop
   .size  Default_Handler, .-Default_Handler

.align 4

/* Адрес регистра управления прерываниями NVIC. */

NVIC_INT_CTRL_CONST: .word 0xe000ed04