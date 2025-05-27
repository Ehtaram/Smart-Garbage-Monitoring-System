# Smart Garbage Monitoring System (IoT)

A lightweight embedded system to optimize waste collection using **ultrasonic sensors**, **ESP8266 WiFi modules**, and **graph-based decision logic**. Developed as a prototype at **Lovely Professional University (Mar–May 2020)**.

## Key Features
- Models a **sensor mesh** as a dynamic graph:
  - Nodes = Smart Bins  
  - Edges = WiFi communication links
- Uses **ultrasonic sensors** to detect bin fill levels (<5cm threshold)
- Prioritizes full bins using local computation on **NodeMCU (ESP8266)**
- Displays real-time status via dynamically generated webpages

## How It Works
- On each loop, the microcontroller measures bin level using ultrasonic echo
- If bin is full, it updates a simple embedded HTTP server
- Each bin communicates its status wirelessly, forming a mesh of data
- Route optimization logic can reduce garbage truck routes by ~30% (theoretical)

## Tech Stack
- **Language**: C++  
- **Hardware**: NodeMCU (ESP8266), Ultrasonic Sensor  
- **Networking**: AT Commands, Embedded HTTP Server  
- **Tools**: Arduino IDE, Serial Debugging  

## Research Relevance

This project serves as an early exploration into **graph-based urban modeling** and **logic-driven control** — relevant to **Composite AI** themes like:
- **Declarative representations** of real-world systems (e.g., bin status as logical predicates)
- **Infrastructure graphs** with dynamic state propagation
- **Explainable decision-making** in sensor networks

> **Note:** This is a compact prototype, designed for clarity and fast iteration. Future work could extend into:
> - Integration with Datalog or Prolog for decentralized route planning  
> - Visual dashboards and city-scale simulations  

## Getting Started

1. Flash code to NodeMCU via Arduino IDE  
2. Power the ultrasonic sensor and ESP8266 module  
3. Connect to WiFi access point created by ESP8266  
4. Open your browser and view real-time bin status at `192.168.4.1`

## Project Info
- **Title:** Smart Garbage Monitoring System  
- **University:** Lovely Professional University  
- **Duration:** Mar – May 2020  
- **Keywords:** IoT, Graph Optimization, Embedded Systems, Sensor Networks  
