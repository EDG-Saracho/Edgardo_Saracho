# Edgardo Saracho

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Divs Flotantes</title>
    <style>
        /* Contenedor principal */
        .container_about {
            display: flex;
            justify-content: space-between;
            width: 100%;
        }

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
            transition: background-color 0.3s ease;
        }

        /* Cambio de color al pasar el ratón por el botón */
        .left-div button:hover {
            background-color: #282826;
        }

        /* Estilos del div derecho */
        .right-div {
            flex: 1;
            display: flex;
            justify-content: center;
            align-items: center;
        }

        /* Estilo para la imagen dentro del div derecho */
        .right-div img {
            max-width: 100%;
            max-height: 100%;
        }

        html {
             min-height: 100%;
             position: relative;
                }
        body { margin: 0;
               margin-bottom: 40px;
                }
    </style>
</head>
<body>
    <div class="container_about">
        <!-- Div izquierdo con texto y botón -->
        <div class="left-div">
            <p>Licenciado en Diseño Industrial - Producto de la Escuela Universitaria Centro de Diseño (EUCD). Técnico Terciario en Diseño Gráfico egresado de la Escuela Comunicación Social.</p>

            <p>Actualmente me desempeño como docente G°1 en las asignaturas Identidad visual (EUCD), Taller de diseño transversal (LDCV) y en Género y comunicación visual (LDCV), dentro de la FADU. También cuento con una marca propia de diseño de interfaces para relojes digitales.</p>

            <p>He trabajado como diseñador en varias empresas, por lo que tengo experiencia en desarrollo de identidades corporativas, papelería, piezas publicitarias, banners, diseño editorial, ilustración, presentación de productos, desarrollo web y mobile, UI & UX.</p>

            <p>Me gusta el diseño en general, investigar y aprender cosas nuevas. Soy autodidacta y busco seguir creciendo como profesional.</p>

            <button onclick="window.location.href='https://www.behance.net/edg_uy'" target="_blank">Portfolio</button>
        </div>
        <div class="right-div">
            <img src="../images/perfil.png" alt="Imagen" ></img>
        </div>
    </div>
</body>
</html>


