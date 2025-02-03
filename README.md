<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Motion-Activated Servo Control with PIR Sensor</title>
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
    </ul>
    <h2>📜 Additional Notes</h2>
    <p>Although the diagram includes multiple sensors, only an <strong>IR sensor</strong> was used in practice. Additionally, the Arduino was grounded through a cable from the <strong>buck converter</strong>, while the sensor received its grounding from the Arduino.</p>

</body>
</html>
