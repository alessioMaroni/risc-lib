# Development Process

**Document ID:** DEV-PROC-001\
**Version:** 1.0.0-draft\
**Status:** Draft for review\
**Applies to:** All project-owned software repositories\
**Owner:** Project maintainers\
**Last updated:** 2026-11-15

------------------------------------------------------------------------

## 1. Purpose and Principles

This document defines the common software engineering, quality
assurance, and development-governance framework for all project-owned
repositories.

Its purpose is to establish consistent practices for developing
deterministic, verifiable, maintainable embedded software, while
creating a foundation that can support future safety-critical and
space-software activities.

This document defines project policies and principles. Detailed
operational procedures, tool configurations, templates, and acceptance
criteria may be defined in subordinate documents.

> **Core compliance principle:** The project shall never claim
> compliance, verification, or assurance that cannot be supported by
> objective, documented evidence. This principle applies throughout the
> software lifecycle.

### 1.1 Compliance and Applicability Tiers

Rules and process activities shall be classified according to their
implementation status:

  -----------------------------------------------------------------------
  Tier                    Definition              Example
  ----------------------- ----------------------- -----------------------
  **Mandatory**           Required for all work   Applying the adopted
                          within the stated scope MISRA C:2025 baseline
                          from the effective date to new project-owned C
                          of the rule.            code.

  **Conditional**         Required when specified Concurrency controls
                          architectural,          when shared state,
                          technical, or           interrupts, multicore
                          operational conditions  execution, or
                          apply.                  concurrent tasks are
                                                  introduced.

  **Planned**             A future objective that Establishing a
                          has not yet been fully  tailored, project-wide
                          implemented. It shall   ECSS assurance process.
                          not be represented as   
                          an operational          
                          practice.               
  -----------------------------------------------------------------------

The tier applies to each rule or activity, not necessarily to an entire
standard. A reference may contain requirements that fall into different
tiers.

The project shall maintain an accurate distinction between planned
activities and activities that are actually implemented and evidenced.

------------------------------------------------------------------------

## 2. Baseline Standards and References

The project uses a focused set of standards and references. Their
inclusion does not, by itself, constitute a claim of compliance or
certification.

  -----------------------------------------------------------------------
  Domain                  Reference               Purpose and application
  ----------------------- ----------------------- -----------------------
  **C coding standard**   MISRA C:2025            Primary
                                                  coding-guideline
                                                  baseline for
                                                  project-owned C code.
                                                  Mandatory for new C
                                                  code, subject to
                                                  documented
                                                  applicability and
                                                  deviation management.

  **Space software        ECSS-E-ST-40C Rev.1     Reference for software
  engineering**                                   engineering processes.
                                                  Applicable requirements
                                                  shall be selected
                                                  through documented
                                                  tailoring before
                                                  claiming alignment or
                                                  compliance.

  **Space software        ECSS-Q-ST-80C Rev.2     Reference for software
  assurance**                                     product assurance.
                                                  Applicable requirements
                                                  shall be selected
                                                  through documented
                                                  tailoring before
                                                  claiming alignment or
                                                  compliance.

  **Secure C coding**     SEI CERT C              Complementary
                                                  secure-coding guidance.
                                                  A specific edition or
                                                  dated ruleset and
                                                  applicable subset shall
                                                  be identified before it
                                                  is treated as an
                                                  adopted project
                                                  baseline.

  **Software weakness     CWE                     Taxonomy for
  classification**                                classifying and
                                                  tracking software
                                                  weaknesses. CWE is a
                                                  classification
                                                  resource, not a
                                                  development or
                                                  certification standard.
  -----------------------------------------------------------------------

### 2.1 Standard Tailoring and Claims

ECSS references shall be tailored to the project's scope, intended use,
development context, and maturity.

The project shall not claim blanket ECSS compliance merely because
selected practices have been adopted. Any claim of alignment or
compliance shall identify:

-   the exact standard and revision;
-   the requirements selected as applicable;
-   requirements excluded or tailored out, with rationale;
-   the evidence used to demonstrate satisfaction;
-   known limitations and unresolved gaps.

The same principle applies to any other external standard or guideline
adopted by the project.

------------------------------------------------------------------------

## 3. Scope and Applicability

### 3.1 Repository Governance

This process applies to all project-owned repositories that contain or
support project software, including:

-   platform-independent architecture and core libraries;
-   processor-specific implementations and backends;
-   SoC- and board-specific support;
-   hardware abstraction layers and device drivers;
-   bootloaders and startup code;
-   middleware and target firmware;
-   project-owned test and verification software where applicable.

Repositories may define stricter local rules. They shall not weaken the
common baseline without an approved process amendment or formally
authorized deviation.

Repository-specific applicability shall be recorded where the
repository's purpose, language, or lifecycle makes a rule inapplicable.

### 3.2 Covered Languages

The initial language scope is:

-   **C:** governed by the adopted MISRA C:2025 baseline and applicable
    project rules.
-   **Assembly:** governed by documented internal low-level coding and
    review guidelines.

Other languages introduced later shall have an explicitly defined
coding, review, and verification approach before being used in
project-critical components.

MISRA C rules shall not be represented as directly governing Assembly
source code.

### 3.3 Included Components

The process covers project-owned software components, including source
code, public interfaces, build configuration, startup code, drivers,
tests, and supporting scripts where they can affect the delivered
software or its verification.

### 3.4 External Dependencies and Third-Party Code

External dependencies include vendor SDKs, libraries, toolchains,
generated code, and imported repositories.

Before integration, each dependency shall be assessed proportionately
for:

-   identity, version, and provenance;
-   license and usage restrictions;
-   integrity, using checksums or signatures where available and
    appropriate;
-   known defects and security advisories where relevant;
-   build and runtime impact;
-   applicable verification limitations.

Third-party code is not automatically compliant with project coding
rules. The project shall record whether it is used unchanged, wrapped,
patched, configured, or replaced. Any claim about its quality or
compliance must be supported by evidence.

External dependencies shall be isolated where practical so that their
code and assumptions do not silently become part of project-owned
components.

------------------------------------------------------------------------

## 4. Coding Standards

### 4.1 C Code --- MISRA C:2025

MISRA C:2025 shall be integrated into the normal development workflow
rather than treated as a pre-release checklist.

For project-owned C code within scope:

-   Every applicable guideline shall be respected.
-   Potential violations shall be identified, analyzed, and resolved or
    handled through the deviation process.
-   Each deviation shall have a technical rationale, impact assessment,
    and documented approval.
-   Deviations shall be identifiable, reviewable, and periodically
    reconsidered when relevant.
-   Static analysis shall be performed regularly and integrated into
    automated checks as the tooling permits.
-   The analyzer, version, configuration, rule coverage, and known
    limitations shall be recorded.

A clean compiler build or the absence of compiler warnings does not, by
itself, demonstrate MISRA compliance.

The project shall distinguish between: - a guideline violation; - an
approved deviation; - a guideline not applicable to the component; - a
guideline that has not yet been checked.

No unverified category shall be reported as compliant.

### 4.2 Existing C Code

When existing code is brought under this process, its status shall be
assessed rather than silently treated as compliant.

A baseline assessment shall identify known violations, deviations,
excluded files, and unverified areas. New or modified code shall follow
the current rules. Existing violations may be addressed incrementally
under a documented remediation plan, without implying that the entire
legacy codebase is already compliant.

### 4.3 Assembly Code

Assembly routines shall follow project-specific low-level guidelines.
These guidelines shall address, as applicable:

-   register and calling-convention usage;
-   stack alignment and stack ownership;
-   preservation of required registers;
-   privilege and execution-mode assumptions;
-   interrupt and exception entry/exit behavior;
-   memory ordering and synchronization assumptions;
-   interaction with compiler-generated code;
-   control-flow and error-handling expectations;
-   review and verification requirements.

Assembly changes shall receive explicit review and appropriate
target-level verification. The applicable rules shall be documented in
`CODING_STANDARD.md` or a referenced architecture-specific supplement.

------------------------------------------------------------------------

## 5. Requirements and Traceability

### 5.1 Requirements Engineering

Requirements shall be uniquely identifiable, clear, appropriately
atomic, and verifiable.

Where applicable, each requirement should state: - the required behavior
or property; - the conditions under which it applies; - measurable
acceptance criteria; - its source or rationale; - its verification
method.

Requirements shall avoid unnecessary implementation details unless those
details are themselves constraints.

### 5.2 Bidirectional Traceability

Traceability shall establish an auditable relationship between what the
software is required to do and the evidence used to assess whether it
does so.

Traceability does not require an identifier on every line of code. Its
granularity shall reflect component responsibilities and the level of
risk.

Traceability shall be maintained in both directions:

-   **Forward:** Requirements → Design → Implementation → Verification
    procedure → Verification result.
-   **Backward:** Implementation → Design rationale or decision →
    Requirement or other justified source.

Unjustified or untraceable implementation elements shall be identified
and reviewed. They shall be linked to a valid requirement, design
decision, constraint, or justified engineering need, or removed.

### 5.3 Example Traceability Chain

  -------------------------------------------------------------------------
  Identifier              Artifact                Description
  ----------------------- ----------------------- -------------------------
  `REQ-UART-001`          Requirement             The UART driver shall
                                                  initialize the peripheral
                                                  according to the
                                                  requested configuration.

  `DES-UART-001`          Design                  Design of the driver
                                                  interface and
                                                  register-initialization
                                                  sequence.

  `SRC-UART-001`          Implementation          Source module or relevant
                          reference               implementation location.

  `TEST-UART-001`         Verification procedure  Test procedure checking
                                                  initialization behavior
                                                  and relevant error
                                                  handling.

  `REPORT-UART-001`       Verification result     Recorded test result,
                                                  including the tested
                                                  configuration and
                                                  outcome.
  -------------------------------------------------------------------------

A test procedure and its result are distinct artifacts. A test passing
under one configuration does not prove behavior under all possible
conditions.

### 5.4 Change Impact Analysis

Changes to requirements, architecture, interfaces, source code, build
configuration, or dependencies shall be assessed for their potential
impact.

The assessment shall identify, as applicable:

1.  affected components and repositories;
2.  affected requirements and design artifacts;
3.  affected interfaces and dependent components;
4.  affected tests and verification evidence;
5.  affected documentation, configurations, and dependency records.

Relevant verification activities shall be repeated after the change. The
extent of re-verification shall be justified and recorded.

------------------------------------------------------------------------

## 6. Development, Verification, and Validation

### 6.1 Verification

Verification activities shall determine whether a software item
satisfies its specified requirements and design constraints.

Depending on the requirement, verification may include:

-   static analysis;
-   code inspection and review;
-   unit testing;
-   integration testing;
-   target or hardware testing;
-   analysis, calculation, or other justified technical methods.

Not every requirement can or should be verified exclusively through an
automated test. The verification method shall be appropriate to the
requirement and documented.

### 6.2 Validation

Validation activities shall assess whether the resulting software
satisfies its intended use and operational needs in the relevant
environment.

Validation may require system-level tests, target hardware,
representative operating conditions, or other suitable evaluation
methods. Its scope shall be defined according to the project's maturity
and intended use.

### 6.3 Objective Evidence

Verification and validation activities shall produce evidence
appropriate to the activity. Evidence may include:

-   test procedures and test results;
-   build logs and configuration records;
-   static-analysis reports;
-   review records;
-   inspection or analysis reports;
-   coverage reports;
-   target-hardware test records.

Evidence shall identify enough context to make the result interpretable
and, where practical, reproducible. Relevant context includes software
revision, tool versions, configuration, target hardware, and test
environment.

A successful test is evidence for the conditions tested; it is not, by
itself, proof of complete software correctness.

### 6.4 Testing

Requirements that can be verified by testing shall have corresponding
test procedures or test cases.

Test design shall consider, where relevant:

-   nominal behavior;
-   invalid inputs and error conditions;
-   boundary values and limits;
-   initialization and shutdown behavior;
-   resource exhaustion;
-   timing constraints;
-   concurrency and interrupt interactions;
-   recovery or safe-state behavior.

Tests shall define expected results and acceptance criteria. Test
results shall be recorded.

Code coverage may be used as a supporting metric, but code coverage is
not equivalent to requirements coverage and does not independently
demonstrate correctness. Coverage objectives shall be established when
justified by component criticality and project maturity.

------------------------------------------------------------------------

## 7. Reviews and Core Engineering Practices

### 7.1 Code Review Policy

Changes shall be reviewed before being accepted into the relevant
integration baseline. The review method shall reflect team size and
project maturity.

Review activities are distinguished as follows:

1.  **Automated checks:** Build, static analysis, and automated test
    gates.
2.  **Self-review:** Structured review by the author using the
    applicable checklist.
3.  **Independent review:** Review by a qualified person other than the
    author.

A self-review does not substitute for an independent review. Automated
checks do not substitute for human review where human review is
required.

The review type, scope, reviewer, findings, and disposition of findings
shall be recorded in the pull request, review record, or equivalent
project artifact. During single-developer phases, self-review may be
used where independent review is unavailable; this limitation shall be
explicit.

### 7.2 Core Engineering Practices

  -----------------------------------------------------------------------
  Practice                            Project rule
  ----------------------------------- -----------------------------------
  **Architectural design**            Significant architectural and
                                      interface decisions shall be
                                      documented, for example through
                                      Architecture Decision Records
                                      (ADRs) or design specifications.

  **Static analysis**                 Configured static-analysis checks
                                      shall be run at defined development
                                      gates. Findings shall be resolved
                                      or handled through an approved
                                      process.

  **Testing**                         Testable requirements shall have
                                      appropriate test procedures and
                                      recorded results.

  **Configuration management**        Each release and verification
                                      baseline shall be traceable to an
                                      exact commit, build configuration,
                                      and compiler/toolchain version.

  **Dependency management**           External dependencies shall have
                                      recorded versions and provenance;
                                      checksums or signatures shall be
                                      recorded where available and
                                      appropriate.

  **Defect management**               Defects and anomalies shall be
                                      logged, classified, prioritized,
                                      and resolved or explicitly accepted
                                      by an authorized project decision.
                                      CWE identifiers may be used where
                                      relevant.

  **Documentation**                   Architecture, public APIs,
                                      requirements, verification
                                      procedures, and known limitations
                                      shall be maintained alongside the
                                      code or in controlled project
                                      documentation.

  **Change management**               Changes shall have an identifiable
                                      rationale and an impact assessment
                                      proportionate to their scope and
                                      risk.
  -----------------------------------------------------------------------

------------------------------------------------------------------------

## 8. Technical and Low-Level Guardrails

The following rules apply according to component scope and technical
applicability.

### 8.1 Compiler Diagnostics

Compiler warnings shall be enabled and configured deliberately. For
controlled project builds, warnings should be treated as errors where
supported and practical.

The project shall: - record compiler versions and relevant warning
options; - avoid unexplained warning suppressions; - document the
rationale and scope of any suppression; - review warning changes when
toolchains are upgraded.

A warning introduced by a compiler upgrade shall be assessed rather than
automatically suppressed or assumed to indicate a source-code defect.

### 8.2 C Language Behavior

The implementation shall avoid reliance on undefined behavior.

Unspecified and implementation-defined behavior shall be identified and
assessed. Where implementation-defined behavior is required or
unavoidable, the relevant compiler, target, and documented behavior
shall be identified and controlled. Unspecified behavior shall not be
relied upon where deterministic behavior is required.

### 8.3 Concurrency and Interrupts --- Conditional

When concurrency is present, component design and implementation shall
define rules for:

-   interrupt-service routine responsibilities and execution
    constraints;
-   shared-state ownership and protection;
-   atomic operations and synchronization;
-   memory ordering and barriers;
-   reentrancy and thread/interrupt safety;
-   deadlock, priority inversion, and starvation risks where applicable;
-   multicore communication and synchronization.

The use of `volatile` shall not be treated as a general substitute for
atomicity or synchronization. Concurrency rules shall be documented
before the relevant concurrent functionality is integrated.

### 8.4 Memory and Resource Management

Static allocation should be preferred where appropriate for the target
and system requirements.

Dynamic allocation shall not be introduced into components with
deterministic or critical execution requirements unless its use is
justified, bounded, and supported by an appropriate failure strategy.

Resource acquisition and release, ownership, exhaustion conditions, and
error paths shall be explicitly considered.

### 8.5 Fault Handling

Components shall define their expected behavior for relevant faults,
invalid inputs, hardware errors, and software-detected failures.

Fallback, recovery, safe-state, or fail-stop behavior shall be selected
according to the fault and system requirements. Recovery shall not be
assumed to be possible or safe in every situation.

Fault-handling behavior and its verification method shall be documented
where relevant.

------------------------------------------------------------------------

## 9. Documentation Hierarchy and Process Roadmap

### 9.1 Document Hierarchy

This document, `DEVELOPMENT_PROCESS.md`, defines the common project
policies and principles. Subordinate documents shall define operational
procedures, detailed rules, and templates.

Proposed structure:

``` text
docs/
└── development/
    ├── DEVELOPMENT_PROCESS.md
    ├── CODING_STANDARD.md
    ├── REQUIREMENTS_MANAGEMENT.md
    ├── VERIFICATION_AND_VALIDATION.md
    ├── CONFIGURATION_MANAGEMENT.md
    ├── CODE_REVIEW.md
    └── DEVIATION_MANAGEMENT.md
```

The subordinate documents shall remain consistent with this master
document. If a conflict is identified, it shall be resolved through a
documented review and update rather than by silently applying
contradictory rules.

### 9.2 Incremental Rollout

The process shall be implemented incrementally:

1.  **Phase 1 --- Establish the baseline:** Review and approve this
    master document, identify the repositories and components in scope,
    and record the current applicability of each rule.
2.  **Phase 2 --- Operational procedures:** Create subordinate
    procedures as concrete development activities require them. A
    procedure shall be defined before the project claims that the
    corresponding practice is operational.
3.  **Phase 3 --- Tooling and evidence:** Integrate applicable checks
    into the build and review workflow, and retain the resulting
    evidence.
4.  **Phase 4 --- Periodic review:** Reassess the process when
    architecture, project scope, standards, toolchains, or assurance
    objectives change.

The incremental rollout is intended to avoid premature bureaucracy, not
to weaken mandatory requirements. Rules classified as Mandatory remain
applicable from their stated effective point.

------------------------------------------------------------------------

## 10. Document Control

Changes to this document shall be reviewed and recorded. Each released
revision shall have an identifiable version and change history.

  ---------------------------------------------------------------------------
  Version           Date              Status            Summary
  ----------------- ----------------- ----------------- ---------------------
  1.0.0-draft       2026-11-15        Draft for review  Initial consolidated
                                                        development-process
                                                        baseline.

  ---------------------------------------------------------------------------

**End of document.**
