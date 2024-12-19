# makipad

[![Licencia MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Version](https://img.shields.io/badge/version-1.0-blue)](https://github.com/Clito/makipad/releases)

## Descripción

**makipad** es un macro keypad diseñado por [Clito](https://github.com/Clito) y potenciado por el firmware QMK. Con una amplia personalización y una experiencia de usuario mejorada, **makipad** es perfecto para programadores, gamers y cualquier persona que busque eficiencia en su flujo de trabajo.

## Características

- **Firmware QMK**: Totalmente personalizable y compatible con QMK.
- **Diseño Compacto**: Tamaño reducido sin sacrificar funcionalidad.
- **RGB Personalizable**: Iluminación LED ajustable para un look personalizado.
- **Teclas Programables**: Asigna cualquier función o macro a las teclas.

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

Después de flashear el firmware, puedes comenzar a usar **makipad** conectándolo a tu ordenador. Personaliza las macros y las teclas utilizando QMK Configurator o editando el archivo `keymap.c`.

## Contribuir

¡Las contribuciones son bienvenidas! Siéntete libre de abrir un issue o un pull request. Aquí te mostramos cómo empezar:

1. Fork el proyecto.
2. Crea una nueva rama (`git checkout -b feature/AmazingFeature`).
3. Realiza tus cambios (`git commit -m 'Add some AmazingFeature'`).
4. Haz push a la rama (`git push origin feature/AmazingFeature`).
5. Abre un pull request.

## Licencia

Distribuido bajo la licencia MIT. Consulta `LICENSE` para más información.

---

¡Espero que esto te sea útil, Clito! Si necesitas algún ajuste o quieres añadir más información, solo dímelo.
