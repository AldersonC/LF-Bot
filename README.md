# LF-Bot
## -- The ultimate line following robot --

## Project Outline

### Algorithm

#### 🔧 PID Controller
- Implements PID formula:  
  `output = Kp * error + Ki * integral + Kd * derivative`
- Used to stabilize bot movement and maintain correct path alignment

#### 🧭 Route Handling (including T-Crosses)
- Line-following using virtual or physical QTR sensors
- **T-cross recognition:**
  - Uses multi-sensor logic to detect when three paths intersect
  - Determines direction and executes turn using PID-controlled steering

### Technology Stack
- **JavaScript** – Core logic and control simulation
- **p5.js** – Visualization of the bot, path, and control signals
- **Circuit Knowledge** – Integration of basic electronics concepts:
  - Motor drivers
  - Sensor wiring (QTR sensors interfaced with digital pins on Arduino Uno 3)
  - Power supply management
  - Microcontroller interfaces (e.g., Arduino Uno 3)
- **Bot Programming** – Implements movement control and path navigation using PID
- **3D Modeling Tools** (e.g., Tinkercad, Fusion 360, or Blender)
  - Used to design the physical structure
  - Files can be exported for 3D printing
- **3D Printing**
  - Enables physical prototyping of the bot housing, sensor mounts, and chassis

### Development Phases
- **Phase 1 – PID Simulator Initialization (2025-06-05):**
  - Developed core simulation using p5.js
  - Visualized real-time PID output and bot behavior
- **Phase 2 – Self-Running Optimization Simulation (2025-06-12):**
  - Created an automated loop to run simulations with different PID parameters
  - Selected and displayed the best-performing configurations
- **Phase 3 – 3D Bot Structure Design:**
  - Designed basic robot chassis with motor and sensor mounts
  - Exported STL/OBJ files for 3D printing
  - Ensured design compatibility with virtual simulation
- **Phase 4 – QTR Sensor Integration:**
  - Configured QTR sensors to work with digital pins on Arduino Uno 3 for line detection
  - Verified functionality for accurate line-following

### Output and Results
- Visual and statistical output of optimized PID configurations
- Simulated bot navigating a circus-themed track with T-crosses
- Printable bot design ready for real-world PID testing

### Future Improvements
- Integrate sensor data from real hardware into the simulation loop
- Expand 3D design to include modular parts (e.g., swappable sensor arms)
- Add mobile app interface for tuning PID values wirelessly

## Live Demo
- [First PID simulation that is interactable to show : Click to try the simulation](https://editor.p5js.org/aldersonchiu/full/ngBpZ4XMh)
- [PID Parameter Evaluation Simulation](https://editor.p5js.org/aldersonchiu/sketches/J9hVkWXBf)

## 🛠️ Work Log

| Date       | Task Description                                                               | Notes                       |
| ---------- | ------------------------------------------------------------------------------ | --------------------------- |
| 2025-06-05 | Initialized PID simulator in p5.js                                             | Linked in Algorithm section |
| 2025-06-12 | Made a new Simulation that self runs and outputs the best runs (best fitting) | Linked in Algorithm section |
| 2025-07-03 | QTR Sensors are working and functional with digital pins on Arduino Uno 3     | Verified for line-following, before the code wouldn't work because we had the wrong qtr sensor, ours is for digital signals only while our previous code used analog signals as output. After some Modifications of the code it finally worked. |

## Reference
[To be added]
