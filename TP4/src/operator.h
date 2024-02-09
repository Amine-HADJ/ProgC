/*
* fichier: operator.h
* but: definir les fonctions des operateurs (somme, difference, produit, quotient, modulo, et, ou, negation)
* auteurs: HADJ-HAMDRI MOHAMMED_AMINE / TAHIRI YOUNESS
*/





#ifndef OPERATOR_H
#define OPERATOR_H

int somme(int num1, int num2)
{
    return num1 + num2;
}

int difference(int num1, int num2)
{
    return num1 - num2;
}

int produit(int num1, int num2)
{
    return num1 * num2;
}

int quotient(int num1, int num2)
{
    return num1 / num2;
}

int modulo(int num1, int num2)
{
    return num1 % num2;
}
int et(int num1, int num2)
{
    return num1 & num2;
}

int ou(int num1, int num2)
{
    return num1 | num2;
}

int negation(int num)
{
    return ~num;
}

#endif // OPERATOR_H
