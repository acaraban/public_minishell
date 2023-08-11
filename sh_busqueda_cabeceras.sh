#!/bin/bash

# Verificar si se proporciona un archivo como argumento
if [ $# -eq 0 ]; then
    echo "Uso: $0 archivo"
    exit 1
fi

archivo="$1"

# Verificar si el archivo existe
if [ ! -f "$archivo" ]; then
    echo "El archivo '$archivo' no existe."
    exit 1
fi

# Leer el archivo línea por línea y verificar si comienza con caracteres alfabéticos
while IFS= read -r linea; do
    primer_caracter="${linea:0:1}"
    if [[ $primer_caracter =~ [[:alpha:]] ]]; then
        echo "$linea;"
    fi
    ((contador++))
done < "$archivo"
