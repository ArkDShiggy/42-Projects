.name "YOU SHOULD NOT PASS"
.comment "Vive la potée"

start:	zjmp    %-500
	ldi	%:live, %1, r2
	ldi	%:start, %1, r3
	add r5, r5, r5
	sti     r1, %:live, %1
	fork	%:write

live:	live    %9
	zjmp    %:live

write:	sti	r3, %:start, %-98
	sti	r2, %:start, %-100
	sti	r3, %:start, %-198
	sti	r2, %:start, %-200
	sti	r3, %:start, %-298
	sti	r2, %:start, %-300
	sti	r3, %:start, %-398
	sti	r2, %:start, %-400
	sti	r3, %:start, %-498
	sti	r2, %:start, %-500
	sti	r3, %:start, %-148
	sti	r2, %:start, %-150
	sti	r3, %:start, %-248
	sti	r2, %:start, %-250
	sti	r3, %:start, %-348
	sti	r2, %:start, %-350
	sti	r3, %:start, %-448
	sti	r2, %:start, %-450
	sti	r3, %:start, %-548
	sti	r2, %:start, %-550
	zjmp	%:write
