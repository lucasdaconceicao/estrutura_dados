#!/usr/bin/env python
# -*- coding: utf-8 -*-
import os

# LISTA SIMPLESMENTE ENCADEADA ORDENADA


# classe para criar os nós
# load é o dado e next um referencia para o próximo dado
class Node:
    def __init__(self, load=None, next=None):
        self.load = load
        self.next = next

    def __str__(self):
        return str(self.load)

# a principio current é None
class List:
    def __init__(self, current = None):
        self.node = current # cabeça

    def add(self, load):
        current_ = self.node # current_ é head (cabeça)

        # nova instancia
        if current_ is None:
            no = Node()
            no.load = load
            self.node = no
            return

        if current_.load > load:
            no = Node()
            no.load = load
            no.next = current_
            self.node = no
            return

        while current_.next is not None:
            # se o proximo do header for maior que o num a ser inserido
            # o header <- o proximo
            if current_.next.load > load:
                break
            current_ = current_.next
        
        no = Node()
        no.load = load
        no.next = current_.next
        current_.next = no
        return

    def __str__(self):
        dataToSort = []
        current_ = self.node

        while current_ is not None:
            dataToSort.append(current_.load)
            current_ = current_.next
        
        return "[%s]" %(', '.join(str(i) for i in dataToSort))

    def __repr__(self):
        return self.__str__()        


def menu():
    print "MENU DE OPÇÕES"
    print "1 = Inserir na lista."
    print "2 = Consultar toda a lista."
    print "3 = Sair\n"


def cls():
    os.system('cls' if os.name == 'nt' else 'clear')


if __name__ == "__main__":
    
    print "LISTA SIMPLESMENTE ENCADEADA ORDENADA\n"

    list_ = List()
    op = ''

    while op != 3:
        menu()

        op = int(input("Digite sua opção: "))
        if op < 1 or op > 5:
            cls()
            print "Operação inválida!\n"

        elif op == 1:
            cls()
            num = int(input("Entre com o número desejado: "))
            list_.add(num)

        elif op == 2:
            cls()
            print "Lista ordenada:\n"
            current = list_.node
            while current is not None:
                print current.load
                current = current.next
            
            print "\n\n"
