package com.atguigu.ioc;

/**
 * @version v1.0
 * @Date:2024-01-02
 * @Description: TODO
 * @Author: yuteng
 */
public class DefaultServiceLocator {
    private static ClientServiceImpl clientService = new ClientServiceImpl();
    public ClientServiceImpl createClientServiceInstance() {
        return clientService;
    }

}
