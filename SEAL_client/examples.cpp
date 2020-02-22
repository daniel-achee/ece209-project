// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT license.

#include "examples.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

using namespace std;
using namespace seal;

void error2(const char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
#ifdef SEAL_VERSION
    cout << "Microsoft SEAL version: " << SEAL_VERSION << endl;
#endif

    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];
    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error2("ERROR opening socket");
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error2("ERROR connecting");
    //printf("Please enter the message: ");
    //bzero(buffer,256);
    //fgets(buffer,255,stdin);
    example_performance_test(sockfd);
    /*
    n = write(sockfd,buffer,strlen(buffer));
    if (n < 0) 
         error("ERROR writing to socket");
        */
    /*
    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n < 0) 
         error("ERROR reading from socket");
    printf("%s\n",buffer);
    */
    close(sockfd);
    return 0;
/*
    while (true)
    {
        cout << "+---------------------------------------------------------+" << endl;
        cout << "| The following examples should be executed while reading |" << endl;
        cout << "| comments in associated files in native/examples/.       |" << endl;
        cout << "+---------------------------------------------------------+" << endl;
        cout << "| Examples                   | Source Files               |" << endl;
        cout << "+----------------------------+----------------------------+" << endl;
        cout << "| 1. BFV Basics              | 1_bfv_basics.cpp           |" << endl;
        cout << "| 2. Encoders                | 2_encoders.cpp             |" << endl;
        cout << "| 3. Levels                  | 3_levels.cpp               |" << endl;
        cout << "| 4. CKKS Basics             | 4_ckks_basics.cpp          |" << endl;
        cout << "| 5. Rotation                | 5_rotation.cpp             |" << endl;
        cout << "| 6. Performance Test        | 6_performance.cpp          |" << endl;
        cout << "+----------------------------+----------------------------+" << endl;

        /*
        Print how much memory we have allocated from the current memory pool.
        By default the memory pool will be a static global pool and the
        MemoryManager class can be used to change it. Most users should have
        little or no reason to touch the memory allocation system.
        */
/*
        size_t megabytes = MemoryManager::GetPool().alloc_byte_count() >> 20;
        cout << "[" << setw(7) << right << megabytes << " MB] "
             << "Total allocation from the memory pool" << endl;

        int selection = 0;
        bool invalid = true;
        do
        {
            cout << endl << "> Run example (1 ~ 6) or exit (0): ";
            if (!(cin >> selection))
            {
                invalid = false;
            }
            else if (selection < 0 || selection > 6)
            {
                invalid = false;
            }
            else
            {
                invalid = true;
            }
            if (!invalid)
            {
                cout << "  [Beep~~] Invalid option: type 0 ~ 6" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (!invalid);

        switch (selection)
        {
        case 1:
            example_bfv_basics();
            break;

        case 2:
            example_encoders();
            break;

        case 3:
            example_levels();
            break;

        case 4:
            example_ckks_basics();
            break;

        case 5:
            example_rotation();
            break;

        case 6:
            example_performance_test();
            break;

        case 0:
            return 0;
        }
    }

    return 0;
*/
}