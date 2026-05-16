# Project-C
Personal C and C/ROS robotics prep repo for rebuilding low-level C fluency, practising data structures/tooling, and preparing for ROS/CV work ahead of the Imperial C project and robotics internship.

## Focus

This repo is a reactivation lab, not a beginner C course. The aim is to rebuild speed and sharpness in raw C while also preparing for robotics-adjacent engineering work and first-principles system design interviews.

Main tracks:

- `c-labs/`: small C implementation drills with tests, sanitizers, and clean APIs.
- `interview-prep/`: 40-minute system-design and pseudocode practice.
- `docs/`: reusable notes on tooling, patterns, and project conventions.

## Starting Strategy

The first useful target is not a large project. It is a tight loop:

1. Build one small C component.
2. Test it.
3. Run it with sanitizers.
4. Write down the design tradeoffs.
5. Repeat with a slightly more realistic robotics/system component.

Robotics should be the bias, not the cage. Good practice examples include ring buffers, sensor-log parsers, message queues, finite-state machines, coordinate transforms, serialization, and timing loops. For the internship interview, the same repo should also support generic system-design questions that test reasoning rather than robotics knowledge.

## First Sprint

- Day 1: dynamic array + unit tests + sanitizer build.
- Day 2: ring buffer for streaming sensor-like data.
- Day 3: string/file parser for logs or CSV-style telemetry.
- Day 4: hashmap or lookup table with explicit ownership rules.
- Day 5: tiny event loop or finite-state machine.
- Daily: one 40-minute system-design drill using `interview-prep/system-design-template.md`.
