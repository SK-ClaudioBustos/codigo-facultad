#include <iostream>
#include "body.h"
#include "a.h"
#include "p.h"
#include "imag.h"
/*
1.Una empresa lo contrata para programar un framework que permite escribir html
con objetos de c++, el html que vamos a utilizar no contendrá todos los
elementos del estándar. Dicho html está formado por los
siguientes tags :

• Tag body : contiene uno o más tags pero no puede contener otro body
• Tag p: contiene texto
• Tag img: contiene el nombre de una imagen.
• Tag a: contiene un link y un texto.

Por ejemplo, una página formada por estos tags pueden ser :
<body>
<p> Este es el examen de poo </p>
<img href=”nombreDeUnaImg.jpg” />
<p> Espero que hayas estudiado </p>
<a href=”http://unlink.html”>texto del link </a>
</body>

Realice el modelado de las clases que permitan resolver el problema.
Realice los metodos que crea convenientes para imprimir el html por pantalla
 */

using namespace std;

int main()
{
    Body unBody;
    unBody.set(new A("esto es un texto","www.google.com"));
    unBody.set(new Imag("esto es una imagen.jpg"));
    unBody.set(new P("esto es solo texto"));

    cout << unBody;

    return 0;
}
