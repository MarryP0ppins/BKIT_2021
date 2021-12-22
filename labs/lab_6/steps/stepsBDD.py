from behave import given, when, then
from test import TestBot

@given("Entered data")
def start(context):
    context.a = TestBot()

@when("Test_1!!!!")
def calculation(context):
    context.a.test_1()
    
    
@when("Test_2!!!!")
def calculation(context):
    context.a.test_2()

@then("Completed")
def end(context):
    pass
