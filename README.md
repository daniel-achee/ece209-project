# Analysis of Homomorphic Encryption in Resource Constrained Settings

By Daniel Achee and Jennifer Quintana

## Abstract

This project explores the landscape of private, secure data analytics. If a user wants to analyze data produced by an IoT device without giving away that data to an untrusted third party, then they have several options. One is to perform the analysis locally, which may be impractical given the resource constraints of their IoT device. Another is they can encrypt the data with homomorphic encryption, send it to another more powerful device which can perform the analysis directly on the encrypted data, and receive the results. We will investigate what is the cost of privacy in settings where the more powerful device is still relatively constrained by comparing data analysis on unencrypted data as opposed to homomorphically encrypted data on a low-SWaP SoC. Additionally, if privacy is considered imperative, we may investigate how powerful a machine must be to perform data analysis on homomorphically encrypted data by comparing the performance of a low-SWaP SoC and a more conventional server.

## Prior Literature
1. Manual for Using Homomorphic Encryption for Bioinformatics, https://www.microsoft.com/en-us/research/wp-content/uploads/2015/11/ManualHE-3.pdf
2. CryptoNets: Applying Neural Networks to Encrypted Datawith High Throughput and Accuracy, https://www.microsoft.com/en-us/research/wp-content/uploads/2016/04/CryptonetsTechReport.pdf
- Github Repo for CryptoNets, https://github.com/microsoft/CryptoNets

## Timeline
- January 28th: Boards received from Amazon, initial firmware image compiled.
- February 4th: Generate preliminary design (unencrypted data sample run, metric data baseline established).
- February 18th: Midterm Presentation.
- February 25th: Generate final design (contains both homomorphic encyrption analysis tools and plaintext tools). Obtain data on metrics for comparison (see next section)
- March 4th: Results comparison, generate final report

## Metrics for Comparison between Homomorphic Encyrption and PlainText Data Analysis
- power consumption [W] during processing
- time [s] to process a fixed set of data
- FPGA utilization [PLEs] of the two builds
- HPS (processor) utilization during analysis [CPU %]
