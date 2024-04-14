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
            display:flex; 
            align-content: center; 
            justify-content:center; 
            width: 50%;
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
        .left-div button:hover {
            background-color: #282826;
        }

        /* Estilos del div derecho */
        .right-div {
            display:flex;
            justify-content: center;
            align-items: center;
            width: 50%;
        }

        /* Estilo para la imagen dentro del div derecho */
        .right-div img {
            max-width: 100%;
            max-height: 100%;
        }
    </style>
</head>
<body>
    <div style="display:flex; width: 100%; align-items: flex-start; align-content: flex-start; flex-wrap:wrap;">
        <!-- Div izquierdo con texto y botón -->
        <div class="left-div">
            <p>Texto del div izquierdo aquí.</p>
            <button onclick="window.location.href='https://www.behance.net/edg_uy'" target="_blank">Portfolio</button>
        </div>
        <div class="right-div">
            <img src="'../images/perfil.png'" alt="Imagen" /></img>
        </div>
    </div>
</body>
</html>

