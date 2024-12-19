## Descripción

**makipad** es un macro keypad diseñado por mí, [Clito](https://github.com/Cli7o) y potenciado por el firmware QMK. Con una amplia personalización y una experiencia de usuario mejorada, **makipad** es perfecto para programadores, gamers y cualquier persona que busque eficiencia en su flujo de trabajo.
Dicho trabajo ha sido realizado para la mejora de calificación en la asignatura Sistemas de Adquisición y Control, del grado de Diseño de Videojuegos en la Universidad de Burgos.

## Características

- **Firmware QMK**: Totalmente personalizable y compatible con QMK.
- **Diseño Compacto**: Tamaño reducido sin sacrificar funcionalidad.
- **Teclas Programables**: Asigna cualquier función o macro a las teclas.
- **Hotswap**: flexible en caso de ruptura de switch o rápida personalización.
- **Intcorporación del sensor DS1307**: Esencial para que el proyecto fuese evaluado.

## Instalación

1. Clona el repositorio:
    ```sh
    git clone https://github.com/Clito/makipad.git
    ```
2. Navega al directorio del proyecto:
    ```sh
    cd makipad
    ```
3. Compila el firmware QMK:
    ```sh
    qmk compile -kb makipad -km default
    ```
4. Flashea el firmware a tu macro keypad:
    ```sh
    qmk flash -kb makipad -km default
    ```

## Uso

Después de flashear el firmware, puedes comenzar a usar **makipad** conectándolo a tu ordenador. Personaliza las macros y las teclas utilizando QMK MSYS editando el archivo `keymap.c`.
