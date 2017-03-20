.name "cucuCURSORRRR"
.comment "I will flood you"

start:	zjmp	%-500
	add     r2, r3, r2
	live	%1
	sti     r1, %:live, %1
	sti     r1, %:end, %1
	fork	%:more

live:   live    %1
	zjmp    %:live

more:	fork	%:more
	fork	%:more

end:	add	r4, r4, r4
