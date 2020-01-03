/*
    自己项目调用JSON库 
*/
#include <string.h>
#include <stdlib.h>
#include "log_util.h"
#include "cJSON/cJSON.h"

/*
{
	"name": "seventeen",
	"age": 18,
	"sex": "boy"
}
*/
char text1[] = "{ \"name\" : \"seventeen\" ,\"age\": 18 ,\"sex\":\"boy\" }";
void print_json(cJSON *json)
{
    char *out;
    if (json == NULL)
        return;

    out = cJSON_Print(json);
    log_info("\n%s\n", out);
    free(out);
}
int main(void)
{
    /*解释*/
    {
        cJSON *json;
        json = cJSON_Parse(text1);
        if (!json)
        {
            log_error("Error before: [%s]\n", cJSON_GetErrorPtr());
            return -1;
        }

        print_json(json);
        break_point("");
        cJSON *item;
        item = cJSON_GetObjectItem(json, "name");
        break_point("%s", "break point");
        if (!item)
        {
            log_error("Error before: [%s]\n", cJSON_GetErrorPtr());
            return -1;
        }
        log_info("%s\n", item->string);
        cJSON_Delete(json);
    }
    /*组合*/
    {
        cJSON *root = cJSON_CreateObject();
        cJSON *node1 = cJSON_CreateObject();
        cJSON *node2 = cJSON_CreateObject();
        cJSON *node3 = cJSON_CreateObject();

        cJSON_AddFalseToObject(node1, "node1_key1");
        cJSON_AddTrueToObject(node1, "node1_key2");

        cJSON_AddStringToObject(node2, "node2_key1", "node2_value1");
        cJSON_AddStringToObject(node2, "node2_key2", "node2_value2");

        cJSON_AddNumberToObject(node3, "node3_key1", 1000);
        cJSON_AddNumberToObject(node3, "node3_key2", 2000);

        cJSON_AddItemToObject(root, "root_node1", node1);
        cJSON_AddItemToObject(root, "root_node2", node2);

        cJSON_AddItemToObject(node1, "node1_node3", node3);
        print_json(root);

        cJSON_Delete(root);
    }
    return 0;
}
