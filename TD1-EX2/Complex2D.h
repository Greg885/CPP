//
// Created by grego on 28/09/2026.
//
#ifndef TD1_EX2_COMPLEX2D_H
#define TD1_EX2_COMPLEX2D_H


class Complex2D {
private:
    double reel;
    double imaginaire;

public:
    Complex2D();
    Complex2D(double r, double i);
    Complex2D(double valeur);
    Complex2D(const Complex2D& autre);

    double getReel() const;
    void setReel(double r);

    double getImaginaire() const;
    void setImaginaire(double i);

    Complex2D operator+(const Complex2D& autre) const;
    Complex2D operator-(const Complex2D& autre) const;
    Complex2D operator*(const Complex2D& autre) const;
    Complex2D operator/(const Complex2D& autre) const;
    bool operator<(const Complex2D& autre) const;
    bool operator>(const Complex2D& autre) const;

    void afficher() const;
};
#endif