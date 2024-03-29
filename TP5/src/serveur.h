/*
 * SPDX-FileCopyrightText: 2021 John Samuel
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#ifndef __SERVER_H__
#define __SERVER_H__

#define PORT 8089

/* accepter la nouvelle connection d'un client et lire les données
 * envoyées par le client. En suite, le serveur envoie un message
 * en retour
 */
int renvoie_message(int client_socket_fd, char *data);

int renvoie_message(int client_socket_fd, char *data);

int recois_numeros_calcule(char *data);

#endif // __SERVER_H__
