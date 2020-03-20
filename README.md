# Homomorphic Encryption Implementation For Small SWaP Platforms
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
- February 20th: Received and Configured Raspberry Pi 4
- February 25th: Generate final design (contains both homomorphic encyrption analysis tools and plaintext tools). Obtain data on metrics for comparison (see next section)
- March 4th: Results comparison, generate final report

## Metrics for Comparison of Homomorphic Encyrption on Different Platforms
- time [s] to process a fixed set of data
- HPS (processor) utilization during analysis [CPU %]

# Code Documentation

## Installing Microsoft SEAL
Follow the instructions on https://github.com/Microsoft/SEAL to download the source code and install microsoft SEAL for your respective platform

## Integrating Our Code
Let seal_location be the location of the SEAL library on your system
1. Download our github repo
2. $ cd client_server_performance_test
3. $ cp 6_performance.cpp seal_location/native/examples
4. $ cp examples.h seal_location/native/examples
5. $ cp examples.cpp seal_location/native/examples
6. $ cd seal_location/native/examples
7. $ make
8. cd ../bin

### Running the Server Performance Test
It is important to always start the server before the client or else the client will report "Error connection refused"

$ ./sealexamples [portnumber]

where portnumber is the port that you want to the server to use

Then select option 6 from both the first and second menu. It will hang until you start the client test.

### Running the Client Performance Test

$ ./sealexamples [hostname] [portnumber]

where hostname is the ip address or dns name of the server and server is the port used by the server
Currently the implementation only works when both the client and server are run using the same host. Therfore please specify localhost as the hostname.
Then select option 6 from the first menu and option five from the second menu.

### Running Other Performance Tests

$ ./sealexamples

To run any of the other 10 performance tests you don't need to any command line arguments. Please select the respective test using the menu presented after starting the code.
