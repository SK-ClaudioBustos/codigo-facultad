<?php

/*1) - Realice un script que defina un arreglo de nombre $dias_semana y al cual debemos
asignar cada uno de los días de la misma comenzando por el Domingo. Luego utilice la función
var_dump() para mostrar su contenido. */
    $dias_semana = ["domingo","lunes","martes","miercoles","jueves","viernes","sabado"];
    var_dump($dias_semana);

/*2) - Edite el script anterior y agregue una nueva sentencia que muestre el contenido del
arreglo con la construcción foreach.*/
    echo "<br>";
    foreach($dias_semana as $e)
        echo $e."<br>";

/*3) - Edite el script del punto 2 y agregue la función print_r() para ver el contenido y la
estructura del arreglo $dias_semana.*/
    echo "<br>";
    foreach($dias_semana as $e)
        print_r($e."<br>");

/*4) - Edite el script del punto 2 y ordene el arreglo de forma ascendente y muestre en
pantalla el contenido del mismo. Utilice la función sort().*/
    echo "<br>";
    sort($dias_semana);
    foreach($dias_semana as $e)
        print_r($e."<br>");

/*5) - Edite el script del punto 2 y ordene el arreglo de forma descendiente y muestre en
pantalla el contenido del mismo. */
    echo "<br>";
    rsort($dias_semana);
    foreach($dias_semana as $e)
        echo $e."<br>";

/*
6) - Realice un nuevo script que defina un arreglo asociativo de nombre $persona y al cual
debemos asignar los siguiente valores y mostrarlos en pantalla:
Clave: tipo_documento, Valor: DNI
Clave: numero_documento, Valor: 22.122.122
Clave: apellidos, Valor: Torvalds
Clave: nombres, Valor: Linus
Clave: domicilio, Valor: San Martín 200
Clave: telefono, Valor: 4333093
Clave: edad, Valor: 42*/
    echo "<br>";
    $persona = array(
        "tipo_documento" => "DNI",
        "numero_documento" => "22.122.122",
        "apellidos" => "Torvalds",
        "nombres" => "Linus",
        "domicilio" => "San Martín 200",
        "telefono" => 4333093,
        "edad" => 42
    );
    var_dump($persona);

/*7) - Escriba un script PHP que utilice la función date('Y-m-d') para obtener 
la fecha actual y utilizando la función explode() cambie el formato de la fecha a dd/mm/yyyy, 
muestre la fecha con formato por pantalla.*/
    echo "<br>";
    $fecha = date("y-m-d");
    echo $fecha;
    echo "<br>";
    $fechaCortada = explode("-",$fecha);
    print_r($fechaCortada);

/*8) - Escriba un script PHP que utilice la función strtoupper() para convertir una cadena a
mayúsculas y mostrarla por pantalla. La misma cadena convertirla a minúsculas para luego
mostrarla por pantalla. */
    $cad = "holanda";
    echo "<br>";
    echo strtoupper($cad);
    echo "<br>";
    echo strtolower($cad);

/*9) - Escriba un script PHP que utilice la función trim() para quitar los espacios en blanco de
una cadena. La misma se define con el siguiente texto: “ Programación Avanzada – Taller de
PHP ”. De la cadena anterior se pide mostrar el largo de la misma por pantalla con la función
strlen() antes y después de utilizar la función trim().*/
    echo "<br>";
    $c = " Programación Avanzada – Taller de PHP ";
    echo $c;
    echo "<br>";
    echo strlen($c);
    echo "<br>";
    $c = trim($c);
    echo $c;
    echo "<br>";
    echo strlen($c);
    echo "<br>";

/*10) - Escriba un script PHP que permita crear una cadena a partir de otra utilizando la
función substr(). La cadena inicial es: “Programación Avanzada – Taller de PHP” y la cadena
resultante deberá ser “Programación PHP”. Puede utilizar el operador de concatenación.*/
    $c1 = "Programación Avanzada – Taller de PHP";
    $tam = strlen("Programación Avanzada – Taller de");
    echo substr($c1,0,13).substr($c1,$tam,$tam+3);


/*11) - Escriba un script PHP que permita crear una cadena a partir de un arreglo que
contiene el día, el mes y el año actual. Utilice la función implode() del lenguaje. Debe crear el
arreglo y asignarle el día, el mes y el año actual para luego crear la cadena.*/
    $arreglo_fecha = array("30","08","2022");
    echo "<br>";
    $arreglo_fechaAux =  implode("/",$arreglo_fecha);
    echo $arreglo_fechaAux;
?>