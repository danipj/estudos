@ Daniela Palumbo 166301 Lab 0

	.org 0x200

start:
	set r0, 0x5000
	set r1, 0x200
	add r0, r1 
	add r0, r0
	add r0, r0
	hlt