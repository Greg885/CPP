//
// Created by grego on 28/09/2026.
//
#include "Complex2D.h"
#include <iostream>


Complex2D::Complex2D() {
    reel = 0.0;
    imaginaire = 0.0;
}

Complex2D::Complex2D(double r, double i) {
    reel = r;
    imaginaire = i;
}

Complex2D::Complex2D(double valeur) {
    reel = valeur;
    imaginaire = valeur;
}

Complex2D::Complex2D(const Complex2D& autre) {
    reel = autre.reel;
    imaginaire = autre.imaginaire;
}


double Complex2D::getReel() const { return reel; }
void Complex2D::setReel(double r) { reel = r; }

double Complex2D::getImaginaire() const { return imaginaire; }
void Complex2D::setImaginaire(double i) { imaginaire = i; }


Complex2D Complex2D::operator+(const Complex2D& autre) const {
    return Complex2D(reel + autre.reel, imaginaire + autre.imaginaire);
}

Complex2D Complex2D::operator-(const Complex2D& autre) const {
    return Complex2D(reel - autre.reel, imaginaire - autre.imaginaire);
}

Complex2D Complex2D::operator*(const Complex2D& autre) const {
    double r = (reel * autre.reel) - (imaginaire * autre.imaginaire);
    double i = (reel * autre.imaginaire) + (imaginaire * autre.reel);
    return Complex2D(r, i);
}

Complex2D Complex2D::operator/(const Complex2D& autre) const {
    double denominateur = (autre.reel * autre.reel) + (autre.imaginaire * autre.imaginaire);
    // Note: Dans un code robuste, il faudrait vérifier que le dénominateur n'est pas 0.
    double r = ((reel * autre.reel) + (imaginaire * autre.imaginaire)) / denominateur;
    double i = ((imaginaire * autre.reel) - (reel * autre.imaginaire)) / denominateur;
    return Complex2D(r, i);
}


bool Complex2D::operator<(const Complex2D& autre) const {
    double monModuleCarre = (reel * reel) + (imaginaire * imaginaire);
    double autreModuleCarre = (autre.reel * autre.reel) + (autre.imaginaire * autre.imaginaire);
    return monModuleCarre < autreModuleCarre;
}

bool Complex2D::operator>(const Complex2D& autre) const {
    double monModuleCarre = (reel * reel) + (imaginaire * imaginaire);
    double autreModuleCarre = (autre.reel * autre.reel) + (autre.imaginaire * autre.imaginaire);
    return monModuleCarre > autreModuleCarre;
}

void Complex2D::afficher() const {
    std::cout << reel << (imaginaire < 0 ? " - " : " + ")
              << (imaginaire < 0 ? -imaginaire : imaginaire) << "i";
}
