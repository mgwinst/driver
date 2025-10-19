#include <linux/module.h>
#include <linux/init.h>
#include <linux/completion.h>
#include <linux/slab.h>
#include <linux/dmaengine.h>
#include <linux/dma-mapping.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MGWINST");
MODULE_DESCRIPTION("test_dma");

static void dma_transfer_completed(void *param)
{
    struct completion *cmp = (struct completion *) param;
    complete(cmp);
}

static int __init test_init(void)
{
    dma_cap_mask_t mask;
    struct dma_chan *chan;
    struct dma_async_tx_descriptor *chan_desc;
    dma_cookie_t cookie;
    dma_addr_t src_addr, dst_addr;
    u8 *src_buf, *dst_buf;
    struct completion cmp;
    int status;

    pr_info("test_dma - Init\n");

    dma_cap_zero(mask);
    dma_cap_set(DMA_SLAVE | DMA_PRIVATE, mask);
    chan = dma_request_channel(mask, NULL, NULL);

    if (!chan) {
        pr_err("test_dma - Error requesting DMA channel\n");
        return -ENODEV;
    }

    src_buf = dma_alloc_coherent(chan->device->dev, 1024, &src_addr, GFP_KERNEL);
    dst_buf = dma_alloc_coherent(chan->device->dev, 1024, &dst_addr, GFP_KERNEL);

    memset(src_buf, 0x0A, 1024);
    memset(dst_buf, 0x00, 1024);

    pr_info("test_dma - Before DMA transfer : src_buf[0] == %x\n", src_buf[0]);
    pr_info("test_dma - Before DMA transfer : dst_buf[0] == %x\n", dst_buf[0]);

    chan_desc = dmaengine_prep_dma_memcpy(chan, dst_addr, src_addr, 1024, DMA_MEM_TO_MEM);
    if (!chan_desc) {
        pr_err("test_dma - Error DMA memcpy faild");
        status = -1;
        goto free;
    }

    init_completion(&cmp);

    chan_desc->callback = dma_transfer_completed;
    chan_desc->callback_param = &cmp;

    cookie = dmaengine_submit(chan_desc);

    dma_async_issue_pending(chan);

    if (wait_for_completion_timeout(&cmp, msecs_to_jiffies(3000)) <= 0) {
        pr_err("test_dma - timeout");
        status = -1;
        goto rel;
    }

    status = dma_async_is_tx_complete(chan, cookie, NULL, NULL);
    if (status == DMA_COMPLETE) {
        pr_info("test_dma - DMA transfer complete\n");
        status = 0;
        pr_info("test_dma - After DMA transfer : src_buf[0] == %x\n", src_buf[0]);
        pr_info("test_dma - After DMA transfer : dst_buf[0] == %x\n", dst_buf[0]);
    } else {
        pr_err("test_dma - DMA transfer failed\n");
        status = -1;
    }

rel:
    dmaengine_terminate_all(chan);

free:
    dma_free_coherent(chan->device->dev, 1024, &src_addr, GFP_KERNEL);
    dma_free_coherent(chan->device->dev, 1024, &dst_addr, GFP_KERNEL);


    dma_release_channel(chan);
    return 0;
}

static void __exit test_exit(void)
{

}

module_init(test_init);
module_exit(test_exit);
