#!/bin/bash

# Run the setup to initialize the database
./setup_db

# Run the registration
echo "Running registration..."
./build/register

# Run the login
echo "Running login..."
./build/login

# Run the BMI calculator
echo "Running BMI calculator..."
./build/bmi_calculator

# Run the workout planning
echo "Running workout planning..."
./build/planning

