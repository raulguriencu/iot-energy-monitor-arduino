# IoT Energy Monitor & Cost Analyzer ⚡
A high-precision power monitoring system built with **Arduino (C++)** and **Python**, featuring real-time data logging and cost calculation.

## 📌 Project Overview
This project is an end-to-end IoT solution designed to measure AC current non-invasively. It captures raw analog data from a current transformer, processes it to calculate RMS values, and streams it to a Python environment for long-term data logging and financial analysis.

**Key Achievement:** Successfully calibrated the system to achieve **97.5% accuracy** compared to industrial-grade induction heating specifications.



## 🛠️ Technical Stack
- **Hardware:** Arduino Uno, SCT-013-000 (100A CT Sensor).
- **Embedded:** C++ (EmonLib) with custom noise-filtering algorithms.
- **Backend/Scripting:** Python 3.x for serial data acquisition and logging.
- **Communication:** UART Serial Communication (9600 baud).

## 🚀 Key Features
* **Real-Time Monitoring:** Calculates Active Power (W), Energy (kWh), and Amperage (Irms).
* **Software Noise Gate:** Implemented a threshold filter ($<0.4A$) to eliminate electromagnetic interference (EMI) and ensure a clean 0W reading in standby mode.
* **Cost Tracking:** Dynamic calculation of electricity costs based on local currency (RON) and current kWh rates.
* **Non-Invasive Sensing:** Safe measurement without direct contact with high-voltage conductors.



## 📊 Performance Validation
The system was rigorously tested against a **Tefal Everyday Induction Hob (Model IH2018)**. Validation was performed at the maximum power setting (Level P7) to verify sensor linearity at high currents (~9A).

| Parameter | Theoretical Value (P7 Max) | Measured Value | Accuracy |
| :--- | :--- | :--- | :--- |
| **Power (Watts)** | 2100 W | 2047.10 W | **97.49%** |
| **Current (Amps)** | ~9.1 A | 8.9 A | **97.80%** |

*Observation: The minor 2.5% deviation is attributed to line voltage fluctuations and sensor tolerance, well within the professional range for DIY monitoring solutions.*

## 📂 Project Structure
```text
├── arduino/
│   └── energy_monitor.ino    # Firmware for sampling & RMS calculation
├── python/
│   └── main_logger.py       # Serial listener and CSV data logger
└── docs/
    └── circuit_diagram.png   # Wiring and sensor schematics

