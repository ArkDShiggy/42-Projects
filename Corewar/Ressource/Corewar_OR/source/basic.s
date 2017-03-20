#
# Made by theven_l & polydo_s
#

.name "LeguMan"
.comment "Vive la potée"

start:	zjmp	%-500
	live	%1
	sti	r1, %:live, %1
	sti	r1, %:multi, %1
	sti	r1, %:arr, %1
	ldi	%:encode, %1, r2
	ldi	%:encode, %1, r3
	ldi	%:encode, %1, r4
	aff	r2
	aff	r3
	aff	r4
	fork	%:live
	sub	r4, r3, r4
	sub	r4, r3, r4
	fork	%:multi
	zjmp	%:arr

live:	live	%1
	zjmp	%:live

encode:	live	%10

multi:	live	%1
	sti	r1, %:end, r2
	add	r2, r3, r2
	sti	r1, %:end, r2
	add	r2, r3, r2
	sti	r1, %:end, r2
	add	r2, r3, r2
	sti	r1, %:end, r2
	add	r2, r3, r2
	zjmp	%:multi

arr:	live	%1
	sti	r1, %:start, r4
	sub	r4, r3, r4
	sti	r1, %:start, r4
	sub	r4, r3, r4
	sti	r1, %:start, r4
	sub	r4, r3, r4
	sti	r1, %:start, r4
	sub	r4, r3, r4
	sti	r1, %:start, r4
	sub	r4, r3, r4
	zjmp	%:arr

end:	live	%1
