# Edgardo Saracho

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Divs Flotantes</title>
    <style>
    
        /* Estilos del div izquierdo */
        .left-div {
            flex: 1;
            padding-right: 20px;
        }

        /* Estilo para el botón dentro del div izquierdo */
        .left-div button {
            width: 126px;
            height: 42px;
            background: #59C999;
            border-radius: 26px;
            opacity: 1;
            border: none;
            color: white;
            font-size: 16px;
            cursor: pointer;
        }

        /* Estilos del div derecho */
        .right-div {
        
            display: flex;
            justify-content: center;
            align-items: center;
        }

        /* Estilo para la imagen dentro del div derecho */
        .right-div img {
            max-width: 100%;
            max-height: 100%;
        }
    </style>
</head>
<body>
    <!-- Div izquierdo con texto y botón -->
    <div class="left-div">
        <p>Texto del div izquierdo aquí.</p>
        <button onclick="window.location.href='tu_pagina_web.html'">Portfolio</button>
    </div>

    <div class="right-div">
        <img src=
        " alt="images/perfil.png" />
    </div>
</body>
</html>

