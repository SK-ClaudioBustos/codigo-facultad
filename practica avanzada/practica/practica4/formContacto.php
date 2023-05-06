<!DOCTYPE html>

<html>
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
        <title>Programación Avanzada</title>
        <link rel="stylesheet" href="styles/style-formContacto.css">
    </head>
    <header>
        <img id="encabezado" alt="Encabezado" src="imgs/encabezado.jpg"> 
    </header>
    <body>
        <h1>Formulario de Contacto</h1>
        <br>
        <form action="" method=”post”>
            <div id="campo-info1">
                <div class="info1"><p>Nombre:</p><input type="text" name="nombre"></div>
                <div class="info1"><p>Asunto:</p><input type="text" name="asunto"></div>
                <div class="info1"><p>Correo:</p><input type="text" name="correo"></div>
            </div>

            <div id="campo-info2">
                <input type="text" name="comentario">
                <input type="reset" value="Restablecer">
                <input type="submit" value="Enviar">
            </div>
        </form>
    </body>
    <footer>
        <img id="pie" alt="Pie de Pagina" src="imgs/pie.jpg">
    </footer>

</html>