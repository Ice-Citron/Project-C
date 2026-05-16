# 40-Minute System Design Template

Use this for robotics, CV, backend, embedded, or generic design prompts. Do not force robotics unless the question naturally points there.

## 0-5 min: Clarify

- What is the system supposed to achieve?
- Who uses it?
- What are the inputs and outputs?
- What is in scope and out of scope?
- What scale, latency, reliability, or safety constraints matter?

## 5-10 min: Assumptions

State assumptions explicitly before designing.

Example:

```text
I will assume one robot produces sensor frames at 30Hz, each frame must be processed within 100ms, and temporary frame loss is acceptable but stale decisions are not.
```

## 10-20 min: Core Design

Define:

- External API or user-facing interface.
- Internal data model.
- Main components.
- Data flow between components.
- Storage or memory model, if relevant.

For pseudocode questions, write the smallest clear algorithm first, then discuss edge cases.

## 20-30 min: Tradeoffs

Discuss:

- Correctness and failure modes.
- Performance bottlenecks.
- Reliability and recovery.
- Testing strategy.
- Observability and debugging.
- Security or safety if relevant.

Use these as prompts, not as a cloud checklist:

- Reliability: what breaks, and how does it recover?
- Performance: what is the bottleneck?
- Operational excellence: how do we debug it?
- Security/safety: what bad input or unsafe state matters?
- Cost/simplicity: what is the simplest design that works?

## 30-37 min: Testing

Cover:

- Unit tests for pure logic.
- Integration tests for component boundaries.
- Load or stress tests for throughput.
- Fault injection for dropped inputs, malformed data, timeouts, or memory failures.
- Golden examples for expected behaviour.

## 37-40 min: Summary

Close with:

```text
The design is X. The main tradeoff is Y. The biggest risk is Z, which I would test by doing W.
```

## Useful Default Structure

```text
Goal:
Inputs:
Outputs:
Constraints:
Assumptions:
Components:
Data flow:
Data model:
Algorithm/pseudocode:
Failure modes:
Testing:
Tradeoffs:
Final summary:
```
