<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
</head>
<body>
    <h1>Motion-Activated Servo Control with PIR Sensor</h1>
    <p><strong>Arduino-based servo motion system</strong> that responds to motion detection using a <strong>PIR sensor</strong>. The servos move smoothly in a sinusoidal pattern and switch between movement styles <strong>every 10 seconds</strong>. If no motion is detected, the system stops after <strong>10 seconds</strong>.</p>
    <h2>🚀 Features</h2>
    <ul>
        <li><strong>Motion-Activated:</strong> Uses a PIR sensor to start and stop servos dynamically.</li>
        <li><strong>Smooth Servo Motion:</strong> Implements a sine wave motion for fluid transitions.</li>
        <li><strong>Alternating Movement:</strong> Changes between two configurations every <strong>10 seconds</strong>.</li>
        <li><strong>Gradual Transitions:</strong> Prevents jerky movements with smooth blending between configurations.</li>
        <li><strong>Energy Efficient:</strong> Automatically pauses servos after <strong>10 seconds</strong> of no motion.</li>
        <li><strong>Customizable:</strong> Easily adjust speed, angles, and transition timing.</li>
    </ul>
    <h2>🛠 Hardware Requirements</h2>
    <ul>
        <li>Arduino Board (Uno, Mega, etc.)</li>
        <li>4 x Servos (e.g., SG90, MG995)</li>
        <li>PIR Sensor (HC-SR501)</li>
        <li>Wiring and Power Source</li>
    </ul>
    <h2>⚙️ How It Works</h2>
    <ol>
        <li><strong>Startup:</strong> The servos initialize at a neutral position.</li>
        <li><strong>Motion Detection:</strong> The PIR sensor activates the servos when motion is detected.</li>
        <li><strong>Servo Motion:</strong> The servos follow a smooth sine wave movement pattern.</li>
        <li><strong>Alternation:</strong> The motion configuration changes every <strong>10 seconds</strong>.</li>
        <li><strong>Pausing:</strong> If no motion is detected for <strong>10 seconds</strong>, the servos stop.</li>
    </ol>
    <h2>🔧 Customization</h2>
    <ul>
        <li><strong>Speed:</strong> Modify the <code>duration</code> parameter in the configuration arrays.</li>
        <li><strong>Min/Max Angles:</strong> Adjust <code>minAngle</code> and <code>maxAngle</code> values.</li>
        <li><strong>Transition Timing:</strong> Change <code>transitionDuration</code> for faster or smoother transitions.</li>
    </ul>
    <h2>📌 Future Improvements</h2>
    <ul>
        <li>EEPROM support for saving configurations.</li>
        <li>Low-power mode when idle.</li>
        <li>Serial communication for dynamic configuration updates.</li>
        <li>Code is supposed to be tidied up (not gonna happen, likely) as I don't have the physical project anymore.</li>
        <li>The code is overcommented for non-developer readability.</li>
        <li>Issue - fast jerk on startup</li>
    </ul>
    <h2>📜 Additional Notes</h2>
    <p>Although the diagram includes multiple sensors, only an <strong>IR sensor</strong> was used in practice. Additionally, the Arduino was grounded through a cable from the <strong>buck converter</strong>, while the sensor received its grounding from the Arduino.</p>
    <p>Purpose - moving sculpture</p>
    <p>Art and mechanics - Riita Hakkarainen - https://www.riittahakkarainen.com/</p>
    <p>Electronics and code - me</p>
    
![WhatsApp Image 2025-01-27 at 20 01 20_1d1c538a](https://github.com/user-attachments/assets/a7311d2e-7e4a-4ce0-862a-733697f4a356)

![WhatsApp Image 2025-01-28 at 12 45 56_d187349c](https://github.com/user-attachments/assets/e46e3507-f4c3-4da6-91e9-202d29de92f6)

![WhatsApp Image 2025-01-28 at 12 50 44_21603d7c](https://github.com/user-attachments/assets/38e96d13-5ff2-4b91-9ca1-b9cd8273dbf4)

https://github.com/user-attachments/assets/d1071b24-6ba5-4a1e-9254-b2aa4186c774




</body>
</html>
