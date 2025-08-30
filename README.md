# CAN-Dashboard
A vehicle dashboard interface implemented on an LPC2129 microcontroller.  
- **Monitors** speed, RPM, and temperature via CAN bus  
- **Built with** Embedded C, LPC2129, CAN transceiver  
- **Features**: real-time updates with graphical display  
- **Usage**: Upload firmware via JTAG; open serial monitor at 115200 bps

This project demonstrates a real-time dashboard implementation using the CAN (Controller Area Network) protocol, commonly used in automotive and industrial systems. Two nodes are designed: Node A acts as the sensor/sender, transmitting vehicle parameters like speed, RPM, and temperature, while Node B receives and displays this data on an LCD or serial monitor.
