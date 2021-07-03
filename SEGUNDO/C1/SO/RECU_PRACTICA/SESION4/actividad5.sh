#!/bin/bash

PATHNAME=/home/daniel/Escritorio/Daniel/SO/RECU_PRACTICA/SESION4
nombrearchivo=`date +%Y-%j-%T`
ps -ef > $PATHNAME/$nombrearchivo
echo Mi pid= $$ &>> $PATHNAME/$nombrearchivo

