terraform {
    required_providers {
        aws = {
            source = "hashicorp/aws"
            version = "~> 4.6"
        }
    }

    required_version = ">= 1.2.0"
}

provider "aws" {
    region = "us-east-1"
}

resource "aws_instance" "app_server" {
    ami = "ami-0c7217cdde317cfec"
    instance_type = "t2.micro"

    tags = {
        Name = "terraform-example"
    }
}