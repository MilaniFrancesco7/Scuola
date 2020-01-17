# Introduzione a Git

## Cos'è Git?

### Introduzione

- Git è un sistema di controllo versione, (VCS, Version Control System), creato per    gestire le modifiche ai file.
- Permette di tracciare ogni modifica al proprio progetto, diventando quindi essenziale per la realizzazione dei progetti più impegnativi.

- Viene creato nel 2005 per sostituire "BitKeeper", di cui linux aveva perso la licenza.

### Inizializzare una repository

- git init 
Crea una repository .git dove potranno essere utilizzati tutti i comandi di Git

### Stato della repository

- git status
Mostra lo stato della repository, dove sono presenti i tracked e gli untracked file.
Git non traccia automaticamente i file

### Fare uno snapshot

- git add * (* per tutto)
Aggiunge i file allo snapshot per il prossimo commit
Lo snapshot rappresenta lo stato del progetto fino a quel momento

### Cartella remota

nome del branch = origin/master
"nomeremoto"/"nomebranch"

### Branch

Sono delle "linee indipendenti di sviluppo"

Ogni repository crea un branch chiamato "master", i commit vengono eseguiti sul branch master.
Per creare un nuovo branch, da un commit qualsiasi, si creerà un altro ramo, senza alterare il ramo master.

Al termine del ramo secondario, se si vuole mantenere le modifiche, si può fare un merge con il ramo master.

>https://learngitbranching.js.org/

### Remotes

Permette di creare delle repository locali scaricandole da github o gitlab ecc.

origin -> Nome di default per le repository locali



## Configurazione per cartella remota
```bash
git config --global user.email "email" #Configurazione della email
git config --global user.name "username" #Configurazione dell'username

git init #inizializza una repository

git clone "url" #Clona la repository in locale

nano .bashrc #Per modificare gli aliases
aliases=gl = 'git log --oneline'
```
## Comandi
```bash
git init #Inizializzare una repository .git
git status #Controllare lo stato delle modifiche e gli untracked file
git log #Storico dei commit realizzati
git log --oneline #Formato compresso

git add "nomefile" #Aggiungere un file alla lista per il prossimo commit
git add * (o .) #Aggiungi tutti i file alla lista per il prossimo commit

git commit -m"messaggio" #"Tasto della fotocamera", Snapshot, registare un messaggio

git config --global user.email "email" #Configurazione git
git config --global user.name "username" #Configurazione git

git tag -a v1.0 -m "Messaggio" //Taggare i file

git revert "idcommit" #Torna indietro creando un altro commit uguale al precedente

git checkout"caratteri/tag" #Sposta il puntatore che di solito punta all'ultimo commit, per controllare una versione precedente del programma
git checkout -b "nomebranch" #Crea un nuovo branch e ci sposta il puntatore
git checkout master #Torna all'ultimo commit
git checkout origin/master #branch della repository remota


git reset --hard #Lascia inalterati i file non tracciati (file nuovi), torna al commit precedente di quelli tracciati
git clean -f #Elimina tutti i file untracked

git branch -d "nomebranch" #Eliminare un branch
git merge "nomebranch" #Esegue il merge del branch a cui si è fatto il checkout con il nome branch
git rebase "nomebranch" #Si utilizza per mostrare una sequenzialità nella progettazione nonostante i branch siano stati sviluppati in modo parallelo

git branch -f "branchname" "posizione" #Riassegna il branch ad un commit specifico

git reset HEAD # Torna al commit precedente
git revert HEAD # Crea un commit successivo sovrascrivendo le modifiche


git clone "url" # copia la cartella in locale

git fetch #scarica la repository remota, ma non aggiorna il master
git pull #Aggiorna il master -> fetch e merge insieme
git push #Carica le modifiche nella repository remota

```
## Rete scolastica
```bash
#Nella cartella principale:
nano .gitconfig

#gitconfig
[http]
	proxy = 172.30.1.199:3128
[https]
	proxy = 172.30.1.199:3128
```

## Aliases
```bash
gl = git log --oneline
ga = git add
gc = git commit -m
gs = git status
```

git checkout -b nomebranch
git reset --hard
git clean -f
git init
git add
git commit
git branch

<!--stackedit_data:
eyJoaXN0b3J5IjpbLTU0MTUyOTUyOCwtNjA1Mzg2MTY4XX0=
-->