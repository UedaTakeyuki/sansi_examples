# sansi_examples

A sample project of how to protect your application against unauthorized copying, with the **sansi** library.

The sansi is a license manager library for Linux (x86 and ARM) and Mac (x86), by working with [Koshinto](https://koshinto.uedasoft.com/docs/) service, it provides an **out-of-the-box copy protection** feature to your application.

## How sansi protect your application against unauthorized copying by working with [Koshinto](https://koshinto.uedasoft.com/docs/)
The **confirm()** function provided by sansi 

```mermaid
sequenceDiagram;
participant Your Application
participant Sansi in your Application
participant Koshinto
participant Sansi in unauthorized copy of Your Application
participant unauthorized copy of Your Application

Your Application->>Sansi in your Application: confirm()
Sansi in your Application->>Koshinto: 環境情報
Koshinto-->>Sansi in your Application: 一致
Sansi in your Application-->>Your Application: true

unauthorized copy of Your Application->>Sansi in unauthorized copy of Your Application: confirm()
Sansi in unauthorized copy of Your Application->>Koshinto: 環境情報
Koshinto-->>Sansi in unauthorized copy of Your Application: 不一致
Sansi in unauthorized copy of Your Application-->>unauthorized copy of Your Application: false
```

The sansi embedded in your application can be operated through the Koshinto Service. You can download the Sansi library from your account of Koshinto, and perform all operations such as setting and changing keys from your mobile device through Koshinto's web interface.

For detail of **Sansi** and **Koshinto**, refer https://koshinto.uedasoft.com/docs/.

## Embed sansi into your application
