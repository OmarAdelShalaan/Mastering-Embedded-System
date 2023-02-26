.global reset @can be show from linker script @ show from sympole table

reset: 
	ldr sp, =stack_top @Load in Reg
	bl 	main		@branch label
stop: 
	b stop
