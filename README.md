# sansi_examples

A sample project of how to protect your application against unauthorized copying, with the **sansi** library.

The sansi is a license manager library for Linux (x86 and ARM) and Mac (x86), by working with [Koshinto](https://koshinto.uedasoft.com/docs/) service, it provides an **out-of-the-box copy protection** feature to your application.

## Why the sansi is an out-of-the-box copy protection.

Because the sansi **does not use license definition files nor license key** that can be cumbersome to acquire and manage properly and can cause weaknesses and accidents.
Instead, the information that determines whether an application can be run is securely stored in koshinto in combination with the Bind_id that uniquely identifies the application.
Each sansi library has a unique Bind_id embedded internally as binary since at the time you have downloaded it from the koshinto.

## How sansi protect your application against unauthorized copying by working with the koshinto.
sansi provides the function **confirm()** for your application.
The confirm() collects various environmental information (e.g.  IP address, Mac address, device unique ID, SD card unique ID, etc.) that can be used to uniquely identify the environment in which the application is executed, and sends it to koshinto together with Bind_id.

Koshinto compares the sent environment information with the stored execution conditions and responds whether the application can be executed or not.
The confirm () returns it to the application as a return value.


Therefore, you can protect your application from piracy simply by **checking the return value of confirm () at your application start point and exiting if it is not OK**. That's it!

```mermaid
sequenceDiagram;
participant Your Application
participant Sansi
participant Koshinto
participant Sansi in Copied App
participant Copied your Application

Your Application->>Sansi: confirm()
Sansi->>Koshinto: Environmental infos, Bind_id
Koshinto-->>Sansi: match !
Sansi-->>Your Application: true

Copied your Application->>Sansi in Copied App: confirm()
Sansi in Copied App->>Koshinto: Environmental infos, Bind_id
Koshinto-->>Sansi in Copied App: not match !
Sansi in Copied App-->>Copied your Application: false
```

## How to get started.

Refer Koshinto document of [get-started](https://koshinto.uedasoft.com/docs/guide/getting-started/signup.html).

## How to embed sansi into your application
The dependency of the sansi is only with **libssl** and **libcrypto** of the **OpenSSL**. So you can embed sansi library in your application by just link with the openssl and their dependencies like as follows:

```
 -lssl -lcrypto -lpthread -ldl -lm
 ```
