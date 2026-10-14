## Overview

Flexible Software Package (FSP) for Renesas RX MCU Series

FSP is the next generation RX MCU software package from Renesas, that enables HMI devices and IoT connectivity through production ready peripheral drivers, Azure RTOS or FreeRTOS, and portable middleware stacks.
FSP includes best-in-class HAL drivers with high performance and low memory footprint. Middleware stacks with Azure RTOS or FreeRTOS integration are included to ease implementation of complex modules like communication.
The e² studio IDE provides support with intuitive configurators and intelligent code generation to make programming and debugging easier and faster.

FSP uses an open software ecosystem and provides flexibility in using your preferred RTOS, legacy code, and third-party ecosystem solutions.

### Current Release

[FSP v1.0.0](https://github.com/renesas/rx-fsp/releases/tag/v1.0.0)

### Supported RX MCU Kits

- EK-RX74M
- EK-RX74N
- MCK-RX74M
- MCK-RX74N

### Supported Software Packaged with FSP

For a list of software modules packaged with FSP, see [Supported Software](SUPPORTED_SOFTWARE.md).

#### Important Notice Regarding Azure RTOS

On November 21, 2023, Microsoft announced that they have decided to contribute Azure RTOS to open source under the stewardship of the Eclipse foundation and Azure RTOS will become Eclipse ThreadX. For detailed information, please refer to the announcement at [Microsoft Contributes Azure RTOS to Open Source](https://techcommunity.microsoft.com/t5/internet-of-things-blog/microsoft-contributes-azure-rtos-to-open-source/ba-p/3986318).

The support strategy scheme for Eclipse ThreadX will be determined and communicated at a later date. Microsoft will discontinue the Azure RTOS and Azure RTOS Middleware under the existing agreement [LICENSED-HARDWARE.txt](https://github.com/eclipse-threadx/threadx/blob/v6.4.0_rel/LICENSED-HARDWARE.txt).

It is important to note that updates for Azure RTOS on these hardware will no longer be provided.

### Product Security Advisories

[Product Security Advisories](https://github.com/renesas/rx-fsp/issues?q=label%3Aproduct_security_advisory) for FSP and third party software (where available) are tagged with the 'product_security_advisory' label. Please check these issues for information from the respective vendors for affected versions and a recommended workaround or patch upgrade.

### Known Issues

[Visit GitHub Issues for this project.](https://github.com/renesas/rx-fsp/issues)

[Critical issues](https://github.com/renesas/rx-fsp/issues?q=label%3Acritical+is%3Aclosed) that cause an MCU to operate out of the hardware manual documented specifications are tagged with the 'critical' label. Please check critical issues before going to production for a workaround or recommended patch upgrade.

### Setup Instructions

#### For existing users that are using FSP with e² studio

- FSP versions of 1.0.0 and later require a minimum e² studio version of 2026-07.

If you have already installed a previous FSP release that included e² studio then you can download the packs separately. These are available for download under the Assets section for each release. There is a zipped version, RX_FSP_Packs_\<version\>.zip, and an installer version, RX_FSP_Packs_\<version\>.exe.

- When using the zipped version of the packs the zip file should be extracted into the e² studio support area. This directory is typically found under the user's home directory with a path such as `~/.eclipse/com.renesas.platform_2047834950`. The number on the end of the path is unique to each e² studio installation. If you have two e² studio installations then you will have two directories with names of the format `~/.eclipse/com.renesas.platform_<unique_number>`. Please note that e² studio must have been run at least once for this directory to be created. You can find the support area for a particular e² studio installation by clicking `Help >> About e² studio`. In the window that pops up click `Installation Details` and choose the `Support Folders` tab. The e² studio support area path will be shown.

#### For new users that are using FSP with e² studio

1.	Download the FSP with e² studio Installer from the Assets section of the [current release](https://github.com/renesas/rx-fsp/releases/tag/v1.0.0).
2.	Run the installer. This will install the e² studio tool, FSP packs, toolchains (GCC and CC-RX) and other tools required to use this software. No additional installations are required.

#### If using RX Smart Configurator (RXSC) with IAR Embedded Workbench

1. See [RXSC User Guide for IAR](https://renesas.github.io/rx-fsp/_s_t_a_r_t__d_e_v.html#RXSC-IAR-user-guide). 

### Starting Development

1. Open e² studio and click File > New > Renesas C/C++ Project > Renesas RX.
2. In the window that pops up, choose the type of template for the project you are creating:
   - Renesas RX C/C++ FSP project: For a single project
   - Renesas RX FSP Solution: For multiple projects 
3. Enter project name and location. 
4. Click Next.
5. In the Project Configuration window, select the hardware and software environment.
   - Select the FSP version.
   - Select the Board for your application. 
     - You can select an existing RX MCU Evaluation Kit or select Custom User Board for any of the RX MCU devices with your own BSP definition.
   - Select the Device. 
     - The Device is automatically populated based on the Board selection. Only change the Device when using the Custom User Board (Any Device) board selection.
   - Select the toolchain and version.
   - Select the Debugger. 
6. Click Next.
7. Select Flat or Protect Zone Project.
   - Flat Project: Without Protect Zone separation. RX device will remain in secure mode.
   - Protect Zone Secure Project: For Protect Zone execution. All code, data, and peripherals will be initialized as secure.
   - Protect Zone Non-secure Project: For Protect Zone non-secure execution. All code, data, and peripherals will be initialized as non-secure.
   
   For more details, please refer to the detailed explanation of each selection in the window.
8. Select None / Preceding Project or Smart Bundle. 
   - For Flat project, select None.
9. In the next window, select the build artifact and RTOS.
10. Select a project template from the list of available templates. 
    -  If you want to develop your own application, select the basic template for your board, Bare Metal - Minimal.

When the project is created, e² studio displays a summary of the current project configuration in the RX MCU Project Editor.

For more information, refer to [Creating a Project](https://renesas.github.io/rx-fsp/_s_t_a_r_t__d_e_v.html#creating-a-project)

### Related Links

FSP Releases:  https://github.com/renesas/rx-fsp/releases

FSP Documentation: https://renesas.github.io/rx-fsp

FSP Webpage: http://renesas.com/rx-fsp (Under Construction)

RX Product Information: www.renesas.com/rx

RX Product Support Forum: www.renesas.com/rx/forum

e² studio: www.renesas.com/e2studio

Example Projects: https://github.com/renesas/rx-fsp-examples (Under Construction)

Knowledge Base: https://en-support.renesas.com/knowledgeBase/category/30942

Support: www.renesas.com/support
