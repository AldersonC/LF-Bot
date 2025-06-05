/*
This code implements a PID (Proportional-Integral-Derivative) controller simulation using p5.js. It visualizes a moving object that tracks a target position on a canvas using PID control. The user can adjust the PID parameters (P, I, D) using  sliders to observe their effects on the object's movement. Clicking the canvas changes the target position, and the object moves toward it with behavior influenced by the PID tuning.
*/


let targetX;
let posX;
let velX = 0;

let kp = 0.5; // Proportional gain
let ki = 0.01; // Integral gain
let kd = 0.2; // Derivative gain

let integral = 0;
let lastError = 0;

let sliderP, sliderI, sliderD;

function setup() {
  createCanvas(800, 400);
  targetX = width / 2;
  posX = random(width);

  // Create sliders for parameter adjustment
  sliderP = createSlider(0, 2, kp, 0.01);
  sliderP.position(20, height + 10);
  sliderI = createSlider(0, 0.1, ki, 0.001);
  sliderI.position(20, height + 40);
  sliderD = createSlider(0, 1, kd, 0.01);
  sliderD.position(20, height + 70);
}

function draw() {
  background(0);

  // Update PID parameters
  kp = sliderP.value();
  ki = sliderI.value();
  kd = sliderD.value();

  // Display target point
  stroke(255);
  line(targetX, 0, targetX, height);
  noStroke();
  fill(0);
  text("Target", targetX + 5, 20);

  // Calculate error
  let error = targetX - posX;
  integral += error;
  let derivative = error - lastError;

  // PID control output
  let output = kp * error + ki * integral + kd * derivative;

  velX += output;
  velX *= 0.9; // Simulate friction or damping
  posX += velX;

  lastError = error;

  // Draw controlled object
  fill(211);
  ellipse(posX, height / 2, 40, 40);

  // Display parameter values
  fill(255);
  text(`P: ${kp.toFixed(2)} | I: ${ki.toFixed(3)} | D: ${kd.toFixed(2)}`, 20, height - 10);
}

function mousePressed() {
  // Clicking the canvas resets the target position
  targetX = mouseX;
}