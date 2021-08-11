#importamos la libreria 

import csv
print("\n\n\t\t\t\tBienvenido a este programa sobre el estado del semáforo COVID")

#Mandamos a llamar al archivo csv y lo leemos

with open("cov.csv", newline="") as File:  
    reader = csv.reader(File, delimiter=";")
    
    conta = 0 #cuenta los enfermos
    i = -1 #cuenta las filas leidas
    suma_edad = 0 #suma de las edades
    
    #Para cada línea en el archivo(para cada indicador junto con la edad)
    for row in reader:
        if i > 0:  
            
            #si tiene covid
            if float(row[1]) > 0.75:                
                conta += 1 #aumentamos de 1 en 1, los enfermos
            suma_edad += float(row[0]) #juntamos la edad
        i += 1 
    promedio_edad = suma_edad / i #calculamos el promedio de la edad
    
    #Mostramos la situación del semáforo COVID en base a los enfermos
    if conta == 0:
        print("\n\n\tEl semáforo covid se encuentra en color: Verde")
    elif conta >= 1 and conta <= 30:
        print("\n\n\tEl semáforo covid se encuentra en color: Amarillo")
    elif conta >= 31 and conta <= 70:
        print("\n\n\tEl semáforo covid se encuentra en color: Naranja")
    elif conta >= 71 and conta <= 100:
        print("\n\n\tEl semáforo covid se encuentra en color: Rojo")   
    
 # Mostramos los resultados
    print("\nTamaño de la muestra de ciudadanos: %i" % (i))
    print("\nCantidad de enfermos: %i" % (conta))
    print("\nPromedio de la edad de los ciudadanos: %.2f\n" % (promedio_edad))
    
    print("Por favor usa tu cubrebocas")
    print("Al hacerlo te cuidas tú, y a los demás también")
    print("Ayuda a que cada día sea mejor")
    print("Ayuda a que cada día esto termine más rápido :)")
    
    File.close() #cerramos el archivo
