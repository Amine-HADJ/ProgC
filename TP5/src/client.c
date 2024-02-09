/*
 * SPDX-FileCopyrightText: 2021 John Samuel
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "client.h"

/**
 * Fonction pour envoyer et recevoir un message depuis un client connecté à la socket.
 *
 * @param socketfd Le descripteur de la socket utilisée pour la communication.
 * @return 0 en cas de succès, -1 en cas d'erreur.
 */
int envoie_recois_message(int socketfd)
{
  char data[1024];

  // Réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));

  // Demande à l'utilisateur d'entrer un message
  char message[1024];
  printf("Votre message (max 1000 caractères): ");
  fgets(message, sizeof(message), stdin);
  message[strlen(message) - 1] = '\0'; // Supprime le caractère de nouvelle ligne

  
  // Construit le message avec une étiquette "message: "
  strcpy(data, "message: ");
  strcat(data, message);

  // Envoie le message au client
  int write_status = write(socketfd, data, strlen(data));
  if (write_status < 0)
  {
    perror("Erreur d'écriture");
    return -1;
  }

  
  // Réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));

  // Lit les données de la socket
  int read_status = read(socketfd, data, sizeof(data));
  if (read_status < 0)
  {
    perror("Erreur de lecture");
    return -1;
  }

  // Affiche le message reçu du client
  printf("Message reçu: %s\n\n", data);

  return 0; // Succès
}

// FONCTION envoie_operateur_numeros qui envoie un message au serveur sous la forme "operateur numero1 numero2"
int envoie_operateur_numeros(int socketfd)
{

  char data[1024];
  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));

  // Demandez à l'utilisateur d'entrer un message
  char message[100];

  printf("Votre calcul (sous la forme 'op num1 num2': ");

  fgets(message, sizeof(message), stdin);



  // Construit le message avec une étiquette "message: "
  strcpy(data, "calcule: ");
  strcat(data, message);

  // Envoie le message au client
  int write_status = write(socketfd, data, strlen(data));
  if (write_status < 0)
  {
    perror("erreur ecriture");
    exit(EXIT_FAILURE);
  }

  // réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));

  // lecture des données de la socket
  int read_status = read(socketfd, data, sizeof(data));
  if (read_status < 0)
  {
    perror("erreur lecture");
    return -1;
  }

  printf("Resultat recu: %s\n\n", data);
  return 0;
}

int chercher_note_etudiant(char *chemin_fichier)
{
  int note;


  
  FILE *fichier = fopen(chemin_fichier, "r");
  if (fichier != NULL)
  {
    fscanf(fichier, "%d", &note);
    fclose(fichier);
  }
  else
  {
    printf("Impossible d'ouvrir le fichier %s\n", chemin_fichier);
  }

  
  
  return note;
}


int envoi_recois_note(int socketfd)
{
  printf("recherche des notes...\n\n");

  //on recupère les notes

  int notes[5][5]; // 5 étudiants et 5 notes
  memset(notes, 0, sizeof(notes));

  


  for (int k = 0; k < 5; k++)
  {
    printf("\n\nEtudiant %d :\n\n", k+1);
    for (int i = 0; i < 5; i++)
    {

      // chemin fichier sous la forme ../etudiant/i/notek.tkt avec i le numéro de l'étudiant(1 à 5) et k le numéro de la note (1 à 5)

      char chemin_fichier[100];
      memset(chemin_fichier, 0, sizeof(chemin_fichier));

      
      strcat(chemin_fichier, "../etudiant/");
      
      char num_etudiant[2];
      sprintf(num_etudiant, "%d", k + 1);
      strcat(chemin_fichier, num_etudiant);

      strcat(chemin_fichier, "/note");

      char num_note[2];
      sprintf(num_note, "%d", i + 1);
      strcat(chemin_fichier, num_note);

      strcat(chemin_fichier, ".txt");

      // on récupère la note de l'étudiant i pour la note k
      int note = chercher_note_etudiant(chemin_fichier);
      // on met la note dans le tableau a la position k,i
      notes[k][i] = note;

      printf(" note%d: %d\n", i+1, note);

    
    }
  }

  int num_etudiant = 0;
  printf("\n\nQuel étudiant vous intéresse ?\n\n");
  scanf("%d", &num_etudiant);
  getchar(); // Supprime le caractère de nouvelle ligne

  //  Demande à l'utilisateur d'entrer l'opération à réalisé et les notes
  char message[1024];

  printf("Entrez l'operation (sous la forme <'op' n°note n°note> ): ");
  fgets(message, sizeof(message), stdin);
  message[strlen(message) - 1] = '\0'; // Supprime le caractère de nouvelle ligne

  char *op;
  int note1 = 0;
  int note2 = 0;

  sscanf(message,  "%s %d %d", op, &note1, &note2);

  
  
  
  

  


  int notes_a_calculer[2];
  memset(notes_a_calculer, 0, sizeof(notes_a_calculer));
 
  notes_a_calculer[0] = notes[num_etudiant - 1][note1 - 1];
  notes_a_calculer[1] = notes[num_etudiant - 1][note2 - 1];
  

  // Construit le message sous la forme "op num1 num2"
  char formule[20];
  memset(formule, 0, sizeof(formule));
  sprintf(formule, "%s %d %d", op, notes_a_calculer[0], notes_a_calculer[1]); 

  printf("formule: %s\n", formule);

  
  char data[1024];

  // Réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));

  // Construit le message avec une étiquette "code: "
  strcpy(data, "notes: ");

  // on ajoute la formule
  strcat(data, formule);



  // Envoie le message au client
  int write_status = write(socketfd, data, strlen(data));
  if (write_status < 0)
  {
    perror("Erreur d'écriture");
    return -1;
  }

  
  // Réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));

  // Lit les données de la socket
  int read_status = read(socketfd, data, sizeof(data));
  if (read_status < 0)
  {
    perror("Erreur de lecture");
    return -1;
  }

  // Affiche le message reçu du client
  printf("Message reçu: %s\n\n", data);
  
  return 0; // Succès
}

int main()
{
  int socketfd;

  struct sockaddr_in server_addr;

  /*
   * Creation d'une socket
   */
  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if (socketfd < 0)
  {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // détails du serveur (adresse et port)
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  // demande de connection au serveur
  int connect_status = connect(socketfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (connect_status < 0)
  {
    perror("connection serveur");
    exit(EXIT_FAILURE);
  }

  while (1)
  {

    char choix_str[10];

    printf("Que voulez vous faire ?\n 1) Envoyer un message.\n 2) Envoyer un calcul.\n 3) Demande notes étudiants\n 4) Quitter.\n\n");
    
    fgets(choix_str, sizeof(choix_str), stdin); // Lire l'entrée de l'utilisateur comme une chaîne de caractères
    choix_str[strlen(choix_str) - 1] = '\0';    // Supprimer le caractère de nouvelle ligne
    int choix = atoi(choix_str); // Convertir la chaîne en entier


    if (choix == 1)
      envoie_recois_message(socketfd);

    else if (choix == 2)
      envoie_operateur_numeros(socketfd);

    else if (choix == 3)
      envoi_recois_note(socketfd);

    else if (choix == 4)
      break;

    else
      printf("Choix invalide\n");
  }

  close(socketfd);
}
