# Introduzione a Git

### Cos'è Git?

E' un sistema di versioning (controllo di versione), per gestire i cambiamenti dei file.
Tiene traccia di ciascun cambiamento che avviene nel tuo progetto, e chi li ha fatti.

Due sistemi:
> Distribuito
Centralizzato

# Comandi git

```bash
git init //Cartella git
git status //Controllare lo stato delle modifiche
git add "nomefile" //Aggiungere un file
git commit -m"messaggio" //"Tasto della fotocamera", Snapshot, registare un messaggio
git config --global user.email "email" //Configurazione git
git config --global user.name "username" //Configurazione git
git log //Storico dei commit realizzati
git log --oneline //In una sola line
git tag -a v1.0 -m "Messaggio" //Taggare i file
git revert "idcommit" //Torna indietro creando un altro commit uguale al precedente
git checkout[caratteri/tag] //Serve a cambiare il puntatore che di solitao punta all'ultimo commit, per controllare una versione precedente del programma
git checkout master //Torna all'ultimo commit
nano .bashrc //Per modificare aliases
aliases=gl = 'git log --oneline'
git reset --hard //Lascia inalterati i file non tracciati (file nuovi), torna al commit precedente di quelli tracciati
git clean -f //Elimina tutti gli untracked file
```

## Branch

Sono delle "linee indipendenti di sviluppo"

Ogni repository crea un branch chiamato "master", i commit vengono eseguiti sul branch master.
Per creare un nuovo branch, da un commit qualsiasi, si creerà un altro ramo, senza alterare il ramo master.

Al termine del ramo secondario, se si vuole mantenere le modifiche, si può fare un merge con il ramo master.
