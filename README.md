# # CAN-Dashboard 🚗

This project demonstrates a real-time dashboard implementation using the CAN (Controller Area Network) protocol, commonly used in automotive and industrial systems. Two nodes are designed: Node A acts as the sensor/sender, transmitting vehicle parameters like speed, RPM, and temperature, while Node B receives and displays this data on an LCD or serial monitor.
A vehicle dashboard interface implemented on the **LPC2129 ARM7 microcontroller**.  
This project demonstrates real-time monitoring and display of vehicle parameters over the **CAN bus protocol**.

---

## 🔧 Features
- Real-time acquisition of **Speed, RPM, and Temperature** data
- Communication using **Controller Area Network (CAN)**
- Embedded C firmware with **GCC cross-compiler**
- Debugging via **JTAG & Serial Monitor**

---

## 🛠️ Hardware & Tools
- **Microcontroller:** LPC2129 (ARM7)
- **Interface:** CAN Transceiver
- **Tools:** Keil uVision / GCC, GDB, JTAG
- **Protocols:** CAN, UART (debug)

---

## 📂 Project Structure
src/ # Source files

inc/ # Header files

docs/ # Documentation & diagrams

README.md # Project description

