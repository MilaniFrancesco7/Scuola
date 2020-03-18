
# Raid 

Language: Italiano
Paese: Italia
Tastiera: italiana

Nome host: Debian
Password: lasolita

Metodo di partizionamento: Manuale

Selezionare -> sda
Nuovo partizionamento -> si

Seleziona -> Spazio libero
Creare nuova partizione
Dimensione -> 4.0 GB , Primaria, Inizio
Usare come: ext4, /, discard/noatime, etichetta linuxboot
completa

Seleziona -> Spazio libero
Creare nuova partizione
Dimensione -> Tutta, primaria, inizio
Usare come: area di swap
completa

Selezionare -> sdb
Partizionamento uguale al precedente

Configurare il RAID software
Scrivere i cambiamenti -> Si
Creare un device multidisk (MD)
Raid1
device attivi -> 2
device spare-> 0
Seleziona -> sda2,sdb2

Creare un device multidisk(MD)
Raid1
device attivi -> 2
device spare -> 0
seleziona -> sda1,sdb2


<!--stackedit_data:
eyJoaXN0b3J5IjpbLTE0MjUxNDY1ODZdfQ==
-->