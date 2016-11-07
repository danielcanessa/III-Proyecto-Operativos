#!/usr/bin/env python
from operator import sub

#REPRESENTACION DE LOS NUMEROS
uno = (0,0)
dos = (0,1)
tres = (0,2)
cuatro = (1,0)
cinco = (1,1)
seis = (1,2)
siete = (2,0)
ocho = (2,1)
nueve = (2,2)
cero = (3,1)

#POS ACTUAL
current =(1,1)
analizando =(0,0)
numeroMov=0
#PIN

pin = (1,3,1,9)

c = tuple(map(sub, uno, nueve))
print(c)
    #if analizando[0] > 0:
#		print("Der,"+str(abs(analizando[1]))+str(numeroMov)+"\n")
#	elif analizando[0]<0:
#		print("Izq,"+str(abs(analizando[1]))+str(numeroMov)+"\n")
 #   elif analizando[1]<0:
	#	print("Arriba,"+str(abs(analizando[0]))+str(numeroMov)+"\n")
	#elif analizando[0]<0:
	#	print("Abajo,"+str(abs(analizando[0]))+str(numeroMov)+"\n") 

def writeMoves(analizando, current, num):
    global numeroMov
    newMov = tuple(map(sub, analizando, current))
    print("numero de mov es: "+str(numeroMov)+"\n")
    print("voy para el numero: "+str(num)+"\n")
    print("el analziando es: ("+str(analizando[0])+","+str(analizando[1])+")\n")
    print("el movimiento a hacer en x es: "+str(newMov[1])+" en y es: "+str(newMov[0])+"\n")
    numeroMov=numeroMov+1;
    return  

for num in pin:
	if num == 1:
		writeMoves(uno,current,num)
		print("el nuevo current es: ("+str(uno[0])+","+str(uno[1])+")\n")
		current = uno
	elif num == 2:
		analizando = dos
		writeMoves(dos,current,num)
		print("el nuevo current es: ("+str(dos[0])+","+str(dos[1])+")\n")
		current = dos
	elif num == 3:
		analizando = tres
		writeMoves(tres,current,num)
		print("el nuevo current es: ("+str(tres[0])+","+str(tres[1])+")\n")
		current = tres
	elif num == 4:
		analizando = cuatro
		writeMoves(cuatro,current,num)
		print("el nuevo current es: ("+str(tres[0])+","+str(tres[1])+")\n")
		current = cuatro
	elif num == 5:
		analizando = cinco
		writeMoves(cinco,current,num)
		print("el nuevo current es: ("+str(tres[0])+","+str(tres[1])+")\n")
		current = cinco
	elif num == 6:
		analizando = seis
		writeMoves(seis,current,num)
		print("el nuevo current es: ("+str(tres[0])+","+str(tres[1])+")\n")
		current = seis
	elif num == 7:
		analizando = siete
		writeMoves(siete,current,num)
		print("el nuevo current es: ("+str(tres[0])+","+str(tres[1])+")\n")
		current = siete
	elif num == 8:
		analizando = ocho
		writeMoves(analizando,current,num)
		print("el nuevo current es: ("+str(tres[0])+","+str(tres[1])+")\n")
		current = ocho
	elif num == 9:
		analizando = nueve
		writeMoves(analizando,current,num)
		print("el nuevo current es: ("+str(tres[0])+","+str(tres[1])+")\n")
		current = nueve
	else:
		analizando = cero
		writeMoves(analizando,current,num)
		print("el nuevo current es: ("+str(tres[0])+","+str(tres[1])+")\n")
		current = cero
	
 
	
