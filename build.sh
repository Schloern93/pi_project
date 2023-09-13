# This bash is for building the project

#Erstelle build Verzeichniss wenn es noch nicht existiert
mkdir -p build

# Alle unterverzeichnisse im build ordner loeschen
rm -r build/*

#Gehe zum build Ordner
cd build

#Führe cmake aus. Hier wird die Datei im übergeordneten Ordner verwendet
cmake ..

#Führe den build aus
make


