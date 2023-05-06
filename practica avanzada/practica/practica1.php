<?php
/*8) - Realice un script que permita mostrar en pantalla el siguiente texto: Bienvenido al lenguaje
PHP!!!. Recuerde utilizar etiquetas estándares y la construcción echo.*/
    // Permite enviar a la salida estándar el String especificado como parámetro
    echo "Bienvenido al lenguaje PHP!!!";

/*9) - Edite el script anterior y agregue una nueva sentencia que muestre el siguiente texto: “PHP es
un lenguaje de programación interpretado que se ejecuta del lado del servidor”. Utilice la función
print() para mostrar el texto.*/
    // La función print() trabaja de forma idéntica a la construcción echo,no incluye salto de linea
    print("<br>PHP es un lenguaje de programación interpretado que se ejecuta del lado del servidor");

/*10) - Edite el script del punto 2 y agregue un comentario de linea a cada instrucción (echo y print())
indicando la función de cada una.
// Permite enviar a la salida estándar el String especificado como parámetro
// La función print() trabaja de forma idéntica a la construcción echo*/

/*12) - Escriba un script PHP que permita declarar e inicializar variables de los siguientes tipos:
interger, float, string y boolean. Luego muestre en pantalla el valor de cada una de las variables
antes mencionadas.
Recuerde que los nombres de las variables en PHP comienzan con un signo $. */

    $integer = 69;
    $boolean = true;
    $string = "holanda";
    $float = 69.69;
    echo "<br>El valor de la variable es ".$integer;
    echo "<br>El valor de la variable es ".$boolean;
    echo "<br>El valor de la variable es ".$string;
    echo "<br>El valor de la variable es ".$float;

/*13) – Editar el script PHP del punto anterior y verifique que cada variable es del tipo declarado
utilizando las funciones para tal caso (is_int(), is_float(), is_string(), etc.). Luego notifique por
pantalla la verificación de cada una de las variables.*/
    echo "<br>La variable es de tipo float: ".is_float($float);
    echo "<br>La variable es de tipo integer: ".is_integer($integer);
    echo "<br>La variable es de tipo boolean: ".is_bool($boolean);
    echo "<br>La variable es de tipo string: ".is_string($string);

/*14) – Escriba un script PHP que utilice los operadores matemáticos del lenguaje, realizando una
suma, una resta, una multiplicación, una división y resto de la misma definiendo e inicializando dosvariables para llevar a cabo las operaciones antes mencionadas. Deberá ir mostrando los
resultados de cada operación en pantalla y también deberá documentar cada operación.*/
    $var1 = 69;
    $var2 = 42;
    //suma
    echo "<br>El resultado de la suma es: ".($var1 + $var2);
    //resta
    echo "<br>El resultado de la resta es: ".($var1 - $var2);
    //division
    echo "<br>El resultado de la division es: ".($var1 / $var2);
    //multiplicacion
    echo "<br>El resultado de la multiplicacion es: ".($var1 * $var2);

/*
15) – Escriba un script PHP que utilice los operadores de comparación del lenguaje, realizando
una comparación de igualdad, de desigualdad (distinto), una comparación de menor, una de
mayor, menor igual y mayor igual definiendo e inicializando dos variables para llevar a cabo las
operaciones antes mencionadas. Deberá utilizar la sentencia if para determinar en cada caso el
valor de verdad de la comparación, mostrando los resultados de cada operación en pantalla y
también deberá documentar cada operación.
*/  
    echo "<br>";
    echo "<br>";
    $v1 = 123;
    $v2 = 321;
    //operador ternario con echo
    echo ($v1 == $v2) ? "son iguales" : "no son iguales" ;
    //operador ternario en una variable
    echo "<br>";
    $resultado = ($v1 != $v2) ? "son distintos" : "no son distintos";
    echo $resultado;
?>