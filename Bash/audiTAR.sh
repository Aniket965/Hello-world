#!/bin/bash 
#Creación  de  una  auditoría  de  seguimiento  para  archivos  “.tar”,  para  el  script  ha  de hacer todo lo que a continuación se detalla y en el mismo orden:
#a.Copia el archivo “.tar” al directorio /almacenamiento.
#b.Agrega  una  línea  de  separación  a  un  archivo  “.log”  en  el  directorio  /home  del usuario.  Este  archivo  "log"  registra  las  actividades  de  los  archivos  “.tar”  para futuras auditorias.
#c.Agrega el nombre del fichero “.tar” al archivo “log”.
#d.Agrega la fecha y la hora al archivo “log”.
#e.Agrega una lista de los archivos contenidos en el fichero “.tar” al archivo “log”.
#f.Extraiga los archivos contenidos en el fichero “.tar”.
#g.Eliminar el archivo “.tar”.

user=`whoami`
fecha=`date`

if [ -d almacenamiento ]; then
	echo "El directorio almacenamiento existe";
else
	echo "Se ha creado el directorio almacenamiento";
	mkdir almacenamiento;
fi

read -p "Introduce el nombre del fichero '.tar' Sin el '.tar'" file 

if [ -e $file.tar ]; then
	cp $file.tar almacenamiento/;
else
	echo "el fichero $file.tar no existe";
	exit 0	
fi

if ![[ -e audiTAR.log ]]; then
	touch /home/$user/audiTAR.log;
fi

	echo  >> /home/$user/audiTAR.log;
	echo $file.tar >> /home/$user/audiTAR.log;
	echo -n " " >> /home/$user/audiTAR.log;
	echo $fecha >> /home/$user/audiTAR.log;
	tar -vtf $file.tar >> /home/$user/audiTAR.log;

tar -xvf "$file.tar"
rm -rf "$file.tar"

