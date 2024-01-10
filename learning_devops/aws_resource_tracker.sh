############
#AUTHOR : UDAY
# DATE : 02-02-2024
# SCRIPT FOR LISTING AWS INSTANCES
#############

#listing all s3 buckets
echo "Printing list of s3 buckets"
aws s3 ls

#listing all ec2 instance's ID only
echo "Printing list of ec2 instances"
aws ec2 describe-instances --query 'Reservations[].Instances[].InstanceId'
