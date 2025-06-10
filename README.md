| Supported Targets | ESP32 | ESP32-C2 | ESP32-C3 | ESP32-C6 | ESP32-H2 | ESP32-P4 | ESP32-S2 | ESP32-S3 |
| ----------------- | ----- | -------- | -------- | -------- | -------- | -------- | -------- | -------- |

# SquareLine Studio Settings

Using SquareLine Studio please use the component library template of board properties closer to 
ESP32-S3-LCD-Touch-5 that is ESP32-S3-LCD-EV-Board

## How to create UI ESP32-S3 with SquareLine Studio

Go open the SquareLine Studio application then navigate to 'Create' section
1. Choose 'Espressif' board selection and scroll down to ESP32-S3-LCD-EV-Board v1.0.1
2. If the resolution is not reachable (e.g. 1024 x 600)
    2.1. Go to the main setting of SquareLine Studio folder (Usually in C:/Users/{user}/boards/Espressif/esp32_s3_lcd_ev_board_v_1_0_1)
    2.2. Open the 'esp32_s3_lcd_ev_board.slb'
    2.3. Edit the "width_max" and "height_max" to 1024 and 600
    2.4. Save the file then resize the resolution
3. Go to 'Project Settings' in tab menu 'File'
4. Set the 'UI Files Export Path' to the folder inside here in 'components/ui'
5. Rebuild and reflash

## Precautions

When using some of different models of ESP32-S3, (recommended to use ```idf.py menuconfig``` to configure these settings) you can manually change or set the menuconfig for
1. PSRAM Mode (Octal/Quad) ```Component Config > [*] Support for external, SPI-connected RAM > SPI-RAM Config > Mode (QUAD/OCT) of SPI RAM chip in use```
2. Flash Memory ```Serial Flasher Config > Flash Size ()```
3. RGB Bounce Buffer Height ```Example Configuration > Display > RGB Bounce Buffer Height```

Some models of ESP32-S3-LCD are little bit tricky, I suggest that you also try to read and change the headers file in the main of ```lvgl_port.h``` and ```waveshare_rgb_lcd_port.h``` for touchscreen and for RGB settings there

# Using the component manager for downloading dependencies

This example demonstrates how to use [IDF Component Manager](https://pypi.org/project/idf-component-manager/) for downloading dependencies from [the component registry](https://components.espressif.com). More details and use cases of IDF Component Manager can be found in the programming guide under `API Guides` -> `Tools` -> `IDF Component Manager`.

## How to use the example
### Hardware Required

This example is designed to work with any commonly available development kit.

### Build and Flash

Run `idf.py reconfigure` to configure this project. During CMake execution the component manager will process data from the manifest file `./main/idf_component.yml` where 2 dependencies are defined:

- `idf: ">=4.1"` - Specifies required version of ESP-IDF.
- `example/cmp: ">=3.3.3"` - Defines dependency on [example/cmp](https://components.espressif.com/component/example/cmp) component that is used by the main component.

CMake Output:
```
...
Solving dependencies requirements
Updating lock file at /home/user/esp-idf/examples/build_system/cmake/component_manager/dependencies.lock
Processing 2 dependencies:
[1/2] example/cmp
[2/2] idf
...
```

Content of the `./managed_components` directory after successful build:
```
> find  ./managed_components
./managed_components
./managed_components/example__cmp
./managed_components/example__cmp/include
./managed_components/example__cmp/include/cmp.h
./managed_components/example__cmp/LICENSE
./managed_components/example__cmp/README.md
./managed_components/example__cmp/CMakeLists.txt
./managed_components/example__cmp/changelog.md
./managed_components/example__cmp/cmp.c
./managed_components/example__cmp/idf_component.yml
```

Flash the project and run the serial monitor to view the output:

```
idf.py -p PORT flash monitor
```

### Example Output

The example outputs a line from the `cmp_hello` function from the component downloaded by the component manager.

```
Hello from example component!
```
