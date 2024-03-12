package com.atguigu.ioc;

/**
 * @version v1.0
 * @Date:2024-01-02
 * @Description: TODO
 * @Author: yuteng
 */
public class ClientService {
    private static ClientService clientService = new ClientService();
    private ClientService(){}
    public static ClientService createInstance() {
        return clientService;
    }
}
